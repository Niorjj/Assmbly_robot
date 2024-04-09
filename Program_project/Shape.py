import cv2
import numpy as np

# 定义颜色阈值，识别白色
lower_white = np.array([0, 0, 200])
upper_white = np.array([255, 50, 255])

# 打开摄像头
cap = cv2.VideoCapture(0)

while True:
    # 读取一帧图像
    ret, frame = cap.read()
    if not ret:
        break

    # 将图像转换为HSV颜色空间
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # 根据颜色阈值获取白色物体的掩模
    mask = cv2.inRange(hsv, lower_white, upper_white)

    # 查找白色物体的轮廓
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        # 计算物体的轮廓近似
        approx = cv2.approxPolyDP(contour, 0.03 * cv2.arcLength(contour, True), True)
        # 获取轮廓的边数
        sides = len(approx)

        # 根据轮廓的边数确定形状
        shape = "Unknown"
        if sides == 3:
            shape = "Triangle"
        elif sides == 4:
            x, y, w, h = cv2.boundingRect(approx)
            aspect_ratio = float(w) / h
            if 0.95 <= aspect_ratio <= 1.05:
                shape = "Square"
            else:
                shape = "Trapezoid"
        elif sides == 6:
            shape = "Hexagon"
        elif sides > 6:
            shape = "Circle"

        # 绘制轮廓和形状名称
        cv2.drawContours(frame, [approx], -1, (0, 255, 0), 2)
        cv2.putText(frame, shape, (approx.ravel()[0], approx.ravel()[1]), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

    # 显示图像
    cv2.imshow("Frame", frame)

    # 按 'q' 键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头并关闭窗口
cap.release()
cv2.destroyAllWindows()

