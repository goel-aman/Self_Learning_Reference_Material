import numpy as np
import matplotlib.pyplot as plt
import cv2  

def load_img():
    img = cv2.imread('bricks.jpg').astype(np.float32) / 255
    img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    return img

print(load_img())

def display_img(img):
    fig = plt.figure(figsize=(12,10))
    ax = fig.add_subplot(111)
    ax.imshow(img)
    plt.show()

# i = load_img()
# display_img(i)

# # gamma value of less than one will make the image ligher.
# # gamma value of greater than one will make the image darker.

# gamma = 2

# result = np.power(i,gamma)
# display_img(result)

# img = load_img()
# font = cv2.FONT_HERSHEY_COMPLEX
# cv2.putText(img,text='bricks',org = (10,600),fontFace = font,fontScale = 10,color = (255,0,0),thickness = 4)
# display_img(img)


# kernel = np.ones(shape=(5,5),dtype=np.float32) / 25
# print(kernel)

# dst = cv2.filter2D(img,-1,kernel)
# display_img(dst)


# img = load_img()
# font = cv2.FONT_HERSHEY_COMPLEX
# cv2.putText(img,text='bricks',org = (10,600),fontFace = font,fontScale = 10,color = (255,0,0),thickness = 4)
# display_img(img)

# print('reset')

# blurred = cv2.blur(img,ksize=(5,5))
# display_img(blurred)



# #Reloading fresh image
# img = load_img()
# font = cv2.FONT_HERSHEY_COMPLEX
# cv2.putText(img,text='bricks',org = (10,600),fontFace = font,fontScale = 10,color = (255,0,0),thickness = 4)
# display_img(img)

# blurred_img = cv2.GaussianBlur(img,(5,5),10)
# display_img(blurred_img)


# # for doing median blurr
# img = load_img()
# font = cv2.FONT_HERSHEY_COMPLEX
# cv2.putText(img,text='bricks',org = (10,600),fontFace = font,fontScale = 10,color = (255,0,0),thickness = 4)
# display_img(img)

# median_result = cv2.medianBlur(img,5)
# display_img(median_result)

# img = cv2.imread('sammy.jpg')
# img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
# display_img(img)


# noise_img = cv2.imread("sammy_noise.jpg")
# display_img(noise_img)

# median = cv2.medianBlur(noise_img,5)
# display_img(median)


img = load_img()
font = cv2.FONT_HERSHEY_COMPLEX
cv2.putText(img,text='bricks',org = (10,600),fontFace = font,fontScale = 10,color = (255,0,0),thickness = 4)
display_img(img)

blur = cv2.bilateralFilter(img,9,75,75)
display_img(blur)
