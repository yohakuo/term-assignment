key = input("请输入加密密匙：")
enc = input("请输入要加密的字符：")

dec = ord(key) ^ ord(enc)        # 对字符加密
print("加密结果：", chr(dec))

enc = ord(key) ^ dec              # 对字符解密 两个异或连着
print("解密结果：", chr(enc))
