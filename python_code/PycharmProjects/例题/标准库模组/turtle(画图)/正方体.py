import turtle
# 画正面
n = 100
turtle.penup()
turtle.goto(-100, -50)
turtle.pendown()
turtle.pencolor('red')
turtle.begin_fill()
turtle.fillcolor('red')
for i in range(4):
    turtle.forward(n)
    turtle.left(90)
turtle.end_fill()
# 画顶面
turtle.penup()
turtle.goto(-100, n-50)
turtle.pendown()
turtle.pencolor('green')
turtle.begin_fill()
turtle.fillcolor('green')
turtle.left(45)
turtle.forward(int(n * 0.6))   # 倾斜边长为60
turtle.right(45)
turtle.forward(n)
turtle.left(360-135)
turtle.forward(int(n * 0.6))
turtle.end_fill()
# 画右侧面
turtle.left(45)
turtle.penup()
turtle.goto(n-100, -50)
turtle.pendown()
turtle.pencolor('blue')
turtle.begin_fill()
turtle.fillcolor('blue')
turtle.left(135)
turtle.forward(int(n * 0.6))   # 倾斜边长为60
turtle.left(45)
turtle.forward(n)
turtle.left(135)
turtle.forward(int(n * 0.6))
turtle.right(90)
turtle.end_fill()
turtle.done()
