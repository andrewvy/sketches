# This imports the "print()" function to keep
# things compatible with Python 2 + 3.
from __future__ import print_function

# For parsing the cmdline.
import argparse

# OpenCV Library
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
    help = "Path to image")
args = vars(ap.parse_args())

# Reads image as a NumPy array
image = cv2.imread(args["image"])

print("Width: {} pixels".format(image.shape[1]))
print("Height: {} pixels".format(image.shape[0]))
print("Channels: {}".format(image.shape[2]))

# Show image on the screen.
# First param is the title of the window.
# Second param is the actual image.
cv2.imshow("Image", image)
cv2.waitKey(0)

cv2.imwrite("new_image.jpg", image)
