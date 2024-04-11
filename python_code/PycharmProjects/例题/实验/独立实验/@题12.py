# 输入一列字符 计算输入的英文字符，空格和数字以及其他字符的数量
import string
letters = 0   # 统计字母个数
space = 0     # 统计空格个数
digit = 0     # 统计数字个数
others = 0    # 统计其他字符个数
s = input('请输入一个字符串:\n')
i = 0
while i < len(s):
    letter = s[i]  # 获取每个位置的值
    i += 1
    if letter in string.ascii_letters:  # 判断是否是字母
        letters += 1
    elif letter.isdigit():  # 判断是否为数字
        digit += 1
    elif letter.isspace():  # 判断是否为空格
        space += 1
    else:
        others += 1
print("[%s]中字母个数=%d,数字个数=%d,空格个数=%d,其他字符个数=%d"
      % (s, letters, digit, space, others))
