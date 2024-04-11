for letter in 'Python':
    print(letter, end=' ')  # 末尾加空格
print()
chemists = ['道尔顿', '门捷列夫', '拉瓦锡', '诺贝尔']
print("化学家：", end='')
for hxj in chemists:
    print(hxj, end=' ')


mathematicians = ('阿基米德', '牛顿', '高斯', '庞加莱')
print("数学家：", end=' ')
for sxj in mathematicians:
    print(sxj, end=' ')
else:
    print("\n提示：元组遍历完毕！")


universities = ["哈佛大学", "斯坦福大学", "剑桥大学", "麻省理工学院", "加州大学-伯克利", "普林斯顿大学", "牛津大学", "哥伦比亚大学", "加州理工学院", "芝加哥大学"]
print("2017《Times》世界大学排名前3的大学是：")
for i in range(3):
    print(str(i+1)+".", universities[i])