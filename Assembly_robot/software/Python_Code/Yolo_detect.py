import cv2

# 加载YOLO模型及其配置和权重文件
net = cv2.dnn.readNet("yolov3.weights", "yolov3.cfg")

# 获取所有类别的名称
with open("coco.names", "r") as f:
    classes = f.read().strip().split("\n")

# 读取输入图像
image = cv2.imread("your_image.jpg")

# 获取图像的宽度和高度
h, w = image.shape[:2]

# 从图像构建一个blob
blob = cv2.dnn.blobFromImage(image, 1 / 255.0, (416, 416), swapRB=True, crop=False)

# 将blob输入到YOLO模型中以获取检测结果
net.setInput(blob)
layer_names = net.getLayerNames()
output_layers = [layer_names[i[0] - 1] for i in net.getUnconnectedOutLayers()]
outputs = net.forward(output_layers)

# 处理检测结果
for output in outputs:
    for detection in output:
        scores = detection[5:]
        class_id = np.argmax(scores)
        confidence = scores[class_id]

        # 检测置信度阈值
        if confidence > 0.5:
            # 获取目标框的坐标
            box = detection[0:4] * np.array([w, h, w, h])
            (centerX, centerY, width, height) = box.astype("int")

            # 计算左上角坐标
            x = int(centerX - (width / 2))
            y = int(centerY - (height / 2))

            # 绘制目标框和类别标签
            cv2.rectangle(image, (x, y), (x + width, y + height), (0, 255, 0), 2)
            label = "{}: {:.2f}%".format(classes[class_id], confidence * 100)
            cv2.putText(image, label, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

# 显示结果图像
cv2.imshow("Image", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
