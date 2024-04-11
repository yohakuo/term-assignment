bat_tuple = ("百度", "阿里巴巴", "腾讯")
bat_tuple_copy = bat_tuple
print(bat_tuple)
print(bat_tuple_copy)
del bat_tuple

wanyue_tuple = ("柳永", "晏殊", "欧阳修", "秦观", "李清照")
haofang_tuple = ("陆游", "苏轼", "辛弃疾")
ci_author_tuple = wanyue_tuple + haofang_tuple
print("宋朝词人：", ci_author_tuple)
print("李清照是宋朝词人吗？", "李清照" in ci_author_tuple)
print("'岳飞'出现3次的元组：", ("岳飞") * 3)
print("wanyue_tuple<ci_author_tuple?", wanyue_tuple < ci_author_tuple)
