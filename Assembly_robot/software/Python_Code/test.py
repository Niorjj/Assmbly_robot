import cv2

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

    # 显示视频帧
    cv2.imshow("Video", frame)

    # 按下 'q' 键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头资源并关闭所有窗口
cap.release()
cv2.destroyAllWindows()
