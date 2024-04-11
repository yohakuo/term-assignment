import jieba
import jieba.analyse
sentence = "艾萨克·牛顿（1643年1月4日-1727年3月31日）爵士，\英国皇家学会会长，英国著名的物理学家，百科全书式的“全才”，\著有《自然哲学的数学原理》 《光学》。"
# 关键词提取
keywords = jieba.analyse.extract_tags(sentence, topK=20, withWeight=True, allowPOS=('n', 'nr', 'ns'))
for item in keywords:
    print(item[0], item[1])
