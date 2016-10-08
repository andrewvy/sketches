import numpy as np
import cv2

# Init NP array with datatype-size of uint8
# uint8 being unsigned 8-bit integer
canvas = np.zeros((300, 300, 3), dtype = "uint8")

# Remember, BGR order.
green = (0, 255, 0)
cv2.line(canvas, (0, 0), (300, 300), green)
cv2.imshow("Canvas", canvas)
cv2.waitKey(0)

red = (0, 0, 255)
cv2.line(canvas, (300, 0), (0, 300), red, 3)
cv2.imshow("Canvas", canvas)
cv2.waitKey(0)

cv2.rectangle(canvas, (10, 10), (60, 60), green, -1)
cv2.imshow("Canvas", canvas)
cv2.waitKey(0)

centerX = canvas.shape[1] // 2
centerY = canvas.shape[0] // 2

for r in range(0, 175, 25):
    cv2.circle(canvas, (centerX, centerY), r, red)

cv2.imshow("Canvas", canvas)
cv2.waitKey(0)
