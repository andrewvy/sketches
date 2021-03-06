import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
    help = "Path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
cv2.imshow("Original", image)

mask = np.zeros(image.shape[:2], dtype = "uint8")
(centerX, centerY) = (image.shape[1] // 2, image.shape[0] // 2)
cv2.rectangle(mask, (centerX - 75, centerY - 75), (centerX + 75, centerY + 75), 255, -1)
cv2.imshow("Mask", mask)

masked = cv2.bitwise_and(image, image, mask = mask)
cv2.imshow("Masked", masked)

mask = np.zeros(image.shape[:2], dtype = "uint8")
cv2.circle(mask, (centerX, centerY), 100, 255, -1)
cv2.imshow("Circle Mask", mask)

masked = cv2.bitwise_and(image, image, mask = mask)
cv2.imshow("Circle Masked", masked)

cv2.waitKey(0)

