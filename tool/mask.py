import cv2
import matplotlib.pyplot as plt
import numpy as np

imgfile = '1.jpg'
maskfile = '2.png'

img = cv2.imread(imgfile, 4)
mask = cv2.imread(maskfile, 4)

# img = cv2.cvtColor(img,cv2.COLOR_RGB2RGBA)
# mask = cv2.cvtColor(mask,cv2.COLOR_RGB2RGBA)

# sp = mask.shape
# width = sp[0]
# heigh = sp[1]
# for y in range(width):
#     for x in range(width):
#         color_m = mask[x,y]
#         if (color_m[1] < 200):
#             mask[x,y]=[255,255,255]



result = cv2.addWeighted(img, 1, mask, 0.3, 0)

cv2.imwrite('4.png',result)

# plt.imshow(mask)
# plt.show()
