import numpy as np
import cv2 as cv

cap = cv.VideoCapture(0)
def detect_circle(image_path):# 读取图像
    image = cv.imread(image_path)
    if image is None:
        print("无法读取图像")
        return -1
    gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    # 使用霍夫圆检测算法检测圆形
    circles = cv.HoughCircles(gray, cv.HOUGH_GRADIENT, dp=1, minDist=20, param1=50, param2=30, minRadius=0,
                               maxRadius=0)
    if circles is not None: # 存在圆形
        return 1
    else: # 不存在圆形
        return 0

while(True):
    ret, frame = cap.read()
    # img = cv.imread(frame,0)
    img_gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    edges = cv.Canny(img_gray,70,110)
    cv.imshow('edges',edges)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv.destroyAllWindows()