from __future__ import print_function
import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
    help = "Path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
cv2.imshow("Original", image)

# OpenCV will clip!

value = cv2.add(np.uint8([200]), np.uint8([100]))
print("Max of 255: {}".format(value))

value = cv2.subtract(np.uint8([50]), np.uint8([100]))
print("Min of 0: {}".format(value))

# NumPy will WRAP AROUND!

value = np.uint8([200]) + np.uint8([100])
print("Wrap around: {}".format(value))

value = np.uint8([50]) - np.uint8([100])
print("Wrap around: {}".format(value))

# ---

# Create numpy array of just 100, same size as image
# And add the two together.
M = np.ones(image.shape, dtype = "uint8") * 100
added = cv2.add(image, M)
cv2.imshow("Added", added)

M = np.ones(image.shape, dtype = "uint8") * 50
subtracted = cv2.subtract(image, M)
cv2.imshow("Subtract", subtracted)

cv2.waitKey(0)
