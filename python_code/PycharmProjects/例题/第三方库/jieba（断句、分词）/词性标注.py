import jieba.posseg as pseg
words = pseg.cut("中国人民是不可战胜的")
for word, flag in words:
    print('%s %s' % (word, flag))
