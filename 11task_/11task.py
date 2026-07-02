import os
os.system("python -m pip install opencv-python numpy")

import cv2
import numpy as np

image = cv2.imread("image.jpg")

cv2.waitKey(0)

blurred = cv2.GaussianBlur(image, (11, 11), 0)

hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

green_min = np.array((36, 25, 25), np.uint8)
green_max = np.array((70, 255, 255), np.uint8)

green_mask = cv2.inRange(hsv, green_min, green_max)

contours, _ = cv2.findContours(green_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

for contour in contours:
    if cv2.contourArea(contour) < 10:
        continue

    x, y, w, h = cv2.boundingRect(contour)

    center_x = int(x + w / 2)
    center_y = int(y + h / 2)

    cv2.circle(image, (center_x, center_y), 5, (0, 0, 255), -1)

cv2.imshow("Variant 9 Result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()