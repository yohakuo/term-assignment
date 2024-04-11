import turtle
# 没有创建变量保持 动态画完就消失了
turtle.penup()
turtle.goto(100, 0)
turtle.pendown()
turtle.color('red')
turtle.pensize(3)
turtle.circle(50)
turtle.done   # 使绘图容器不消失
