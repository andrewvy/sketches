import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
    help = "Path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
cv2.imshow("Original", image)

# We are setting the width to 150px, so we calculate the ratio
# from converting current width to 150px, and apply that to the
# height.
ratio = 150.0 / image.shape[1]
dim = (150, int(image.shape[0] * ratio))

# Now resize the image.
resized = cv2.resize(image, dim, interpolation = cv2.INTER_AREA)
cv2.imshow("Resized", resized)
cv2.waitKey(0)
