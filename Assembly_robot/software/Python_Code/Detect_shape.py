import cv2
import numpy as np
from scipy.spatial import distance as dist


def detect_shape_contour(image):
    # 将图像转换为灰度图
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # 对图像进行阈值处理
    _, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    # 寻找轮廓
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    detected_shapes = []

    for contour in contours:
        # 这里可以添加一些条件来筛选目标轮廓，比如面积、形状等
        peri = cv2.arcLength(contour, True)
        approx = cv2.approxPolyDP(contour, 0.04 * peri, True)

        # 判断形状
        shape = "unknown"
        if len(approx) == 3:
            shape = "triangle"
        elif len(approx) == 4:
            shape = "rectangle"
        elif len(approx) == 5:
            shape = "pentagon"
        else:
            # 这里可以继续添加更多形状的判断条件
            pass

        detected_shapes.append((approx, shape))

    return detected_shapes


def get_target_shape_contour(image):
    # 将图像转换为灰度图
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # 对图像进行阈值处理
    _, thresh = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
    # 寻找轮廓
    contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    target_contour = None
    target_center = None

    for contour in contours:
        # 这里可以添加一些条件来筛选目标轮廓，比如面积、形状等
        approx = cv2.approxPolyDP(contour, 0.04 * cv2.arcLength(contour, True), True)
        if len(approx) == 4:  # 假设目标是四边形
            target_contour = approx
            m = cv2.moments(contour)
            cx = int(m["m10"] / m["m00"])
            cy = int(m["m01"] / m["m00"])
            target_center = (cx, cy)
            break

    return target_contour, target_center


def get_depth_to_target(image, target_center):
    img_center = (image.shape[1] // 2, image.shape[0] // 2)
    distance = dist.euclidean(img_center, target_center)
    return distance


def main():
    cap = cv2.VideoCapture(0)  # 打开摄像头
    while True:
        ret, frame = cap.read()
        # if not ret:
        #     break

        target_contour, target_center = get_target_shape_contour(frame)
        # 获取目标形状信息
        detected_shapes = detect_shape_contour(frame)

        if target_contour is not None and target_center is not None:
            # 框选目标
            cv2.drawContours(frame, [target_contour], -1, (0, 255, 0), 2)
            # 在目标中心绘制一个点
            cv2.circle(frame, target_center, 5, (0, 0, 255), -1)

            # 获取与摄像头的距离
            distance = get_depth_to_target(frame, target_center)
            cv2.putText(frame, f"Distance: {distance} pixels", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255),
                        2, cv2.LINE_AA)
            cv2.putText(frame, f"Distance: {detected_shapes} pixels", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255),
                        2, cv2.LINE_AA)

        cv2.imshow('Frame', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
