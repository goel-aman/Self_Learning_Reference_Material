import cv2 

# img1 = cv2.imread('dog_backpack.png')
# img1 = cv2.cvtColor(img1,cv2.COLOR_BGR2RGB)
# img2 = cv2.imread('watermark_no_copy.png')
# img2 = cv2.cvtColor(img2,cv2.COLOR_BGR2RGB)

import matplotlib.pyplot as plt

# plt.imshow(img1)
# plt.show()

# plt.imshow(img2)
# plt.show()

# print(img1.shape)

# print(img2.shape)

# #BLENDING IMAGES OF THE SAME SIZE
# img1 = cv2.resize(img1,(1200,1200))
# img2 = cv2.resize(img2,(1200,1200))

# plt.imshow(img1)
# plt.show()

# plt.imshow(img2)
# plt.show()

# blended = cv2.addWeighted(src1 = img1,alpha= 0.8,src2 = img2,beta = 0.1,gamma= 0)
# plt.imshow(blended)
# plt.show()


#OVERLAY SMALL IMAGE ON TOP OF A LARGER IMAGE (NO BLENDING)
# Numpy reassignment

# img1 = cv2.imread('dog_backpack.png')
# img1 = cv2.cvtColor(img1,cv2.COLOR_BGR2RGB)
# img2 = cv2.imread('watermark_no_copy.png')
# img2 = cv2.cvtColor(img2,cv2.COLOR_BGR2RGB)

# img2 = cv2.resize(img2,(600,600))
# print(img2.shape)
# plt.imshow(img2)
# plt.show()

# print("hello aman")
# large_img = img1
# small_img = img2 

# x_offset = 0
# y_offset = 0

# x_end = x_offset + small_img.shape[1]
# y_end = y_offset + small_img.shape[0]
# print(small_img.shape)
# large_img[y_offset:y_end,x_offset:x_end] = small_img

# plt.imshow(large_img)
# plt.show()
#BLEND TOGETHER IMAGES OF DIFFERENT SIZES

img1 = cv2.imread('dog_backpack.png')
img1 = cv2.cvtColor(img1,cv2.COLOR_BGR2RGB)
img2 = cv2.imread('watermark_no_copy.png')
img2 = cv2.cvtColor(img2,cv2.COLOR_BGR2RGB)

img2 = cv2.resize(img2,(600,600))
plt.imshow(img1)
plt.show()

print(img1.shape)

# Here we are trying to put the 

x_offset = 934 - 600
y_offset = 1401 - 600

print(img2.shape)

rows , cols , channels = img2.shape

# Here roi stands for region of interest

roi = img1[y_offset:1401,x_offset:934]

plt.imshow(roi)
plt.show()


img2gray = cv2.cvtColor(img2,cv2.COLOR_RGB2GRAY)
plt.imshow(img2gray,cmap='gray')
plt.show()

mask_inv = cv2.bitwise_not(img2gray)

plt.imshow(mask_inv,cmap= 'gray')
plt.show()

#you will observe that it no longer contains color channels
print(mask_inv.shape)

import numpy as np 
white_background = np.full(img2.shape,255)
print(white_background)

#white_background



bk = cv2.bitwise_or(white_background,white_background,mask = mask_inv)
print(bk.shape)

plt.imshow(bk)
plt.show()

fg = cv2.bitwise_or(img2,img2,mask=mask_inv)
plt.imshow(fg)
plt.show()

final_roi = cv2.bitwise_or(roi,fg)
plt.imshow(final_roi)
plt.show()

large_img = img1
small_img = final_roi

large_img[y_offset:y_offset + small_img.shape[0],x_offset:x_offset + small_img.shape[1]] = small_img

plt.imshow(large_img)
plt.show()

