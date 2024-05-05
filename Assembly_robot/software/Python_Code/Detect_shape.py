import cv2
import numpy as np

# 读取模板图像
template = cv2.imread('test_circle.jpg', 0)
w, h = template.shape[::-1]

# 打开摄像头
cap = cv2.VideoCapture(0)

while True:
    # 读取摄像头捕获的帧
    ret, frame = cap.read()

    # 将帧转换为灰度图像
    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # 执行模板匹配
    result = cv2.matchTemplate(gray_frame, template, cv2.TM_CCOEFF_NORMED)
    threshold = 0.8
    loc = np.where(result >= threshold)

    # 在原始帧上绘制匹配的区域
    for pt in zip(*loc[::-1]):
        cv2.rectangle(frame, pt, (pt[0] + w, pt[1] + h), (0, 255, 255), 2)

    # 显示帧
    cv2.imshow('Template Matching', frame)

    # 按下 'q' 键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头并关闭所有窗口
cap.release()
cv2.destroyAllWindows()
