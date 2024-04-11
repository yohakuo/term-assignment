import jieba
segList1 = jieba.cut("居里夫人1903年获诺贝尔奖时做了精彩演讲", cut_all=True)
print("全模式：", "/".join(segList1))
segList2 = jieba.cut("居里夫人1903年获诺贝尔奖时做了精彩演讲", cut_all=False)
print("精确模式：", "/".join(segList2))
segList3 = jieba.cut_for_search("居里夫人1903年获诺贝尔奖时做了精彩演讲")
print("搜索引擎模式：", ".".join(segList3))