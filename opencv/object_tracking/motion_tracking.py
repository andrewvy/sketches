import numpy as np
import time
import cv2

capture = cv2.VideoCapture("bouncingBall.avi")

frame1 = None
ret, frame = capture.read()
frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
fps = capture.get(cv2.CAP_PROP_FPS)

while(1):
    ret, frame1 = capture.read()

    if ret != True:
        break

    grayscale_frame = cv2.cvtColor(frame1, cv2.COLOR_BGR2GRAY)

    # Diff the current frame with the static BG frame (frame0).
    diff = cv2.absdiff(frame, grayscale_frame)

    # Calculate threshold
    threshold = cv2.threshold(diff, 25, 255, cv2.THRESH_BINARY)[1]

    # Dilate threshold
    threshold = cv2.dilate(threshold, None, iterations = 2)

    # Now find contours
    _, contours, _ = cv2.findContours(threshold.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Loop over contours
    for contour in contours:
        (x, y, w, h) = cv2.boundingRect(contour)
        cv2.rectangle(frame1, (x, y), (x + w, y + h), (0, 255, 0), 2)

    cv2.imshow("Diff", frame1)

    print (1 / fps) * 1000

    k = cv2.waitKey(int((1 / fps) * 1000)) & 0xFF

    if k == 27:
        break

cv2.destroyAllWindows()
capture.release()
