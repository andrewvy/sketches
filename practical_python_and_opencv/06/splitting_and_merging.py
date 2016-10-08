import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
    help = "Path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
cv2.imshow("Original", image)

zeros = np.zeros(image.shape[:2], dtype = "uint8")
(B, G, R) = cv2.split(image)
cv2.imshow("R", cv2.merge([zeros, zeros, R]))
cv2.imshow("G", cv2.merge([zeros, G, zeros]))
cv2.imshow("B", cv2.merge([B, zeros, zeros]))
cv2.waitKey(0)

merged = cv2.merge([B, G, R])
cv2.imshow("Merged", merged)
cv2.waitKey(0)
