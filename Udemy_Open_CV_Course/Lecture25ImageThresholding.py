#converting a color image to binary 
import cv2
import numpy as np  
import matplotlib.pyplot as plt

img = cv2.imread('rainbow.jpg',0)
plt.imshow(img,cmap = 'gray')
plt.show()

# ret, thresh1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
# ret, thresh1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY_INV)
# ret , thresh1 = cv2.threshold(img,127,255,cv2.THRESH_TOZERO)
ret , thresh1 = cv2.threshold(img,127,255,cv2.THRESH_TOZERO_INV)
#ret gives the threshold value 
print(ret)

plt.imshow(thresh1,cmap='gray')
plt.show()


#value of 0 means black and value of 255 means white


# white reading we are passing zero so as to read it as gray scale
img = cv2.imread('crossword.jpg',0)
plt.imshow(img,cmap = 'gray')
plt.show()

def show_pic(img):
    fig = plt.figure(figsize=(15,15))
    ax = fig.add_subplot(111)
    ax.imshow(img,cmap='gray')
    plt.show()

show_pic(img)

ret , th1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
show_pic(th1)

th2 = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,11,8)
show_pic(th2)



blended = cv2.addWeighted(src1=th1,alpha = 0.6,src2 = th2,beta = 0.4,gamma = 0)
show_pic(blended)

