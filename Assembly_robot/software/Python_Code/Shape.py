import cv2

def detect_circle(image_path):
    # 读取图像
    image = cv2.imread(image_path)
    
    if image is None:
        print("无法读取图像")
        return -1
    
    # 转换图像为灰度
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # 使用霍夫圆检测算法检测圆形
    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, dp=1, minDist=20, param1=50, param2=30, minRadius=0, maxRadius=0)
    
    if circles is not None:
        # 存在圆形
        return 1
    else:
        # 不存在圆形
        return 0

# 测试示例
image_path = "test_circle.jpg"  # 请替换为你的图像路径
result = detect_circle(image_path)
print("图像形状是否为圆形：", result)
