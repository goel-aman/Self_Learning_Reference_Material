import cv2 
import numpy as np
import matplotlib.pyplot as plt

img = cv2.imread('dog_backpack.jpg')
img = cv2.resize(img,(0,0),img,0.5,0.5)
img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)

#Now fliping the image upside down
img = cv2.flip(img,0)

#Flipping the image back to normal 
img = cv2.flip(img,0)

#Creating Square on the dog face 
# cv2.rectangle(img,pt1=(100,192),pt2=(301,356),color=(255,0,0),thickness=8)
# plt.imshow(img)
# plt.show()

#Creating Triangle in the figure
vertices = np.array([[191,171],[87,360],[300,360]],dtype = np.int32)
pts = vertices.reshape((-1,1,2))
cv2.polylines(img,[pts],isClosed=True,color = (255,0,0),thickness = 8)
plt.imshow(img)
plt.show()


#Creating Filled  Triangle in the figure
vertices = np.array([[191,171],[87,360],[300,360]],dtype = np.int32)
pts = vertices.reshape((-1,1,2))
cv2.fillPoly(img,[pts],color = (255,0,0))
plt.imshow(img)
plt.show()


while True:

    cv2.imshow('dog_backpack',img)

    if cv2.waitKey(1) & 0xFF == 27:
        break
