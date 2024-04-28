import numpy as np
import cv2 as cv

cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    # img = cv.imread(frame,0)
    img_gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    edges = cv.Canny(img_gray,70,110)
    cv.imshow('edges',edges)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv.destroyAllWindows()