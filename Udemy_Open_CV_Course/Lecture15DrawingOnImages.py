import cv2 
import numpy as np  
import matplotlib.pyplot as plt

blank_img = np.zeros(shape=(512,512,3),dtype=np.int16)
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(blank_img,text="HELLO",org=(10,500),fontFace=font,fontScale=4,color=(255,255,255),thickness=3,lineType=cv2.LINE_AA)
plt.imshow(blank_img)
plt.show()

blank_img = np.zeros(shape=(512,512,3),dtype=np.int32)
plt.imshow(blank_img)
plt.show()

vertices = np.array([[100,300],[200,200],[400,300],[200,400]],dtype=np.int32)
print(vertices.shape)


pts = vertices.reshape((-1,1,2)) # don't try to understand why we need -1,1,2 it is just that cv2 needs that.
print(vertices.shape)
print(pts.shape)


cv2.polylines(blank_img,[pts],isClosed = True,color = (255,0,0),thickness=5)
plt.imshow(blank_img)
plt.show()
