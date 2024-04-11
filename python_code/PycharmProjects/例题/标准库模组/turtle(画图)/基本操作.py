import turtle
turtle.penup()
turtle.goto(-150, 0)
turtle.pendown()
turtle.pencolor('blue')   # 画笔颜色为蓝色
turtle.begin_fill()
turtle.fillcolor('blue')  # 填充颜色为蓝色
for i in range(4):
    turtle.forward(100)   # 画笔向当前方向移动距离100
    turtle.left(90)       # 逆时针旋转90°
turtle.end_fill()