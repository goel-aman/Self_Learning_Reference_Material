import cv2
import numpy as np 
import matplotlib.pyplot as plt



def draw_circle(event,x,y,flags,param):
    if event == cv2.EVENT_RBUTTONDOWN:
        cv2.circle(img,(x,y),100,color=(0,255,0),thickness=1)

cv2.namedWindow(winname='my_dog')
cv2.setMouseCallback('my_dog',draw_circle)

#######################
## showing the image with opencv
#################################

img = cv2.imread("dog_backpack.jpg")
img = cv2.resize(img,(0,0),img,0.5,0.5)

while True:
    cv2.imshow('my_dog',img)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()