import cv2
import numpy as np


def detect_objects(frame):
    # 转换图像为HSV颜色空间
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # 定义颜色范围
    lower_red = np.array([0, 100, 100])
    upper_red = np.array([10, 255, 255])

    lower_blue = np.array([100, 100, 100])
    upper_blue = np.array([140, 255, 255])

    # 根据颜色范围创建掩模
    red_mask = cv2.inRange(hsv_frame, lower_red, upper_red)
    blue_mask = cv2.inRange(hsv_frame, lower_blue, upper_blue)

    # 使用形态学转换进行过滤
    kernel = np.ones((5, 5), np.uint8)
    red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_OPEN, kernel)
    blue_mask = cv2.morphologyEx(blue_mask, cv2.MORPH_OPEN, kernel)

    # 寻找轮廓
    contours, _ = cv2.findContours(red_mask + blue_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    detected_objects = []

def detect_shape(frame):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    _, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        approx = cv2.approxPolyDP(contour, 0.03 * cv2.arcLength(contour, True), True)
        area = cv2.contourArea(contour)
        
        if len(approx) == 3:
            return 3  # 返回3表示三角形
        elif len(approx) == 4:
            # 判断是否是梯形
            _, _, w, h = cv2.boundingRect(approx)
            aspect_ratio = float(w) / h
            if 0.8 < aspect_ratio < 1.2:
                return 2  # 返回2表示方形
            else:
                return 4  # 返回4表示梯形
        elif len(approx) == 6:
            return 5  # 返回5表示六边形
        else:
            return 1  # 返回1表示圆形

    return 0  # 返回0表示未识别出任何形状


if __name__ == "__main__":
    cap = cv2.VideoCapture(0)
# 打开摄像头
cap = cv2.VideoCapture(0)

# 检查摄像头是否成功打开
if not cap.isOpened():
    print("无法打开摄像头，请检查连接")
    exit()

# 设置视频窗口
cv2.namedWindow("Video", cv2.WINDOW_NORMAL)

while True:
    # 读取视频帧
    ret, frame = cap.read()
    # 检查视频帧是否读取成功
    if not ret:
        print("无法读取视频帧")
        break

        # 检测物体
    objects = detect_objects(frame)

    for obj in objects:
        shape, color, center = obj
        cv2.putText(frame, f"{color} {shape}", (center[0], center[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
        cv2.circle(frame, center, 5, (0, 0, 255), -1)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
