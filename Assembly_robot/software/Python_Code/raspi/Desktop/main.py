import cv2
import numpy as np
import serial

# 初始化串口通信
# ser = serial.Serial('/dev/ttyUSB0', 115200)  # 根据实际情况更改串口名称和波特率

lower_white = np.array([0, 0, 200])
upper_white = np.array([180, 50, 255])

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
            # ser.write(data.encode())

            # 在图像上标记目标
            cv2.circle(frame, (cx, cy), 10, (0, 255, 0), -1)  # 在目标中心画一个绿色的圆圈

        # 显示图像
        cv2.imshow('Frame', frame)

        # 按下 'q' 键退出循环
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 释放资源
    cap.release()
    cv2.destroyAllWindows()
