import cv2
import numpy as np
import serial

# 初始化串口通信
ser = serial.Serial('/dev/ttyAMA0', 115200)  # 根据实际情况更改串口名称和波特率

lower_white = np.array([0, 0, 200])
upper_white = np.array([180, 50, 255])


def detect_shape(contour):
    # Approximate the contour to reduce the number of vertices
    peri = cv2.arcLength(contour, True)
    approx = cv2.approxPolyDP(contour, 0.04 * peri, True)

    # Determine the shape based on the number of vertices
    num_vertices = len(approx)
    if num_vertices == 3:
        return "Triangle"
    elif num_vertices == 4:
        return "Rectangle"
    elif num_vertices > 4:
        return "Circle"
    else:
        return "Unknown"


def send_serial_data(x, y, shape):
    data = f"X:{x},Y:{y},Shape:{shape}"
    ser.write(data.encode())


# 读取视频流
cap = cv2.VideoCapture(0)

if __name__ == "__main__":
    while True:
        # 读取一帧
        ret, frame = cap.read()

        # 将BGR图像转换为HSV图像
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # 根据颜色范围创建掩码
        mask = cv2.inRange(hsv, lower_white, upper_white)

        # 执行形态学操作以消除噪音
        mask = cv2.erode(mask, None, iterations=2)
        mask = cv2.dilate(mask, None, iterations=2)

        # 找到目标的轮廓
        contours, _ = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # 如果存在轮廓
        if contours:
            # 寻找最大的轮廓
            max_contour = max(contours, key=cv2.contourArea)
            # 获取目标的边界框
            x, y, w, h = cv2.boundingRect(max_contour)
            # 在图像上框选目标
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

            # 在目标上方添加文字 "target"
            cv2.putText(frame, "target", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

            # 计算目标深度信息（此处省略，根据实际情况实现）

            # 将位置信息和深度信息发送到下位机
            cx = x + w // 2
            cy = y + h // 2
            data = f"X:{cx},Y:{cy},Depth:100"  # 这里的100是示例深度信息
            ser.write(data.encode())

            shape = detect_shape(max_contour)
            cv2.putText(frame, shape, (x + w // 2 - 50, y + h // 2), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

        # 显示图像
        cv2.imshow('Frame', frame)

        # 按下 'q' 键退出循环
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 释放资源
    cap.release()
    cv2.destroyAllWindows()
