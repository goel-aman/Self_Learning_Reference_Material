import numpy as np 
import matplotlib.pyplot as plt  

import cv2
img = cv2.imread('download.jpg')
print(type(img))


print(img)
print(img.shape)

plt.imshow(img)
plt.show()


# Matplotlib --> RGB RED GREEN BLUE
# OPENCV --> BLUE GREEN RED

fix_img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
plt.imshow(fix_img)
plt.show()


#Let Say if we want to read image as gray image then
img_gray = cv2.imread('download.jpg',cv2.IMREAD_GRAYSCALE)
print(img_gray.shape)
plt.imshow(img_gray,cmap = 'gray')
plt.show()


plt.imshow(fix_img)
plt.show()

print(fix_img.shape)
#resizing the image

new_img = cv2.resize(fix_img,(1000,400))
plt.imshow(new_img)
plt.show()

w_ratio = 0.8  # width ratio # 80% of the original height
h_ratio = 0.2 # height ratio # 20% of the original height
# its a bit weird but this is how it works. 
new_img = cv2.resize(fix_img,(0,0),fix_img,w_ratio,h_ratio)


plt.imshow(new_img)
plt.show()

print(new_img.shape)
print(new_img.shape)

new_img = cv2.flip(fix_img,0)
plt.imshow(new_img)
plt.show()

# to flip along vertical axis 

new_img = cv2.flip(fix_img,1)
plt.imshow(new_img)
plt.show()


#to flip both vertical and horizontal use - 1
new_img = cv2.flip(fix_img,-1)
plt.imshow(new_img)
plt.show()


print(type(fix_img))

cv2.imwrite('reversed.jpg',fix_img)
