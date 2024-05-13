import cv2 as cv

retval, corners = cv.findChessboardCorners(image, patternSize, flags)
