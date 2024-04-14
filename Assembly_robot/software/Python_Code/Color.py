#-*-coding:utf-8-*-

import cv2 # type: ignore
import numpy as np

# 输入图像
img = cv2.imread('test_circle.jpg')
#转换为灰度图
img_gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#应用二值阈值
ret, thresh = cv2.threshold(img_gray,150,255,cv2.THRESH_BINARY)

# # 模板图像
# template = cv2.imread('test_circle.jpg')

# # 模型匹配
# result = cv2.matchTemplate(img, template, cv2.TM_CCOEFF_NORMED)

# # 选择最合适目标位置
# min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)

# # 在目标出画一个矩形
# top_left = max_loc
# bottom_right = (top_left[0] + template.shape[0], top_left[1] + template.shape[1])
# cv2.rectangle(img, top_left, bottom_right, (0, 0, 255), 2)

# 输出结果
cv2.imshow('Result', thresh)
cv2.waitKey(0)
cv2.imwrite('image_thres1.jpg',thresh)
cv2.destroyAllWindows()
