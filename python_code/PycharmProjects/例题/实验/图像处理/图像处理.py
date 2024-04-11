from PIL import Image
from PIL import ImageFilter
url = r"C:\Users\23947\Desktop\Figure.jpg"
im = Image.open(url)

w, h = im.size
print('Original image size: %sx%s' % (w, h))

im.thumbnail((w**2, h**2))          # 缩放
print('Resize image to: %sx%s' % (w**2, h**2))

# 把缩放后的图像用jpg格式保存 默认是
im = im.convert('RGB')
im.save('Figure_1.jpeg')

r, g, b = im.split()
om = Image.merge("RGB", (b, g, r))   # 在（b，g，r）将三个字母进行交换得到效果图
om.save('Figure_2.jpeg')                    # 储存文件名


om1 = im.filter(ImageFilter.CONTOUR)
om1.save("Figure_3.jpg")
om1.show()
