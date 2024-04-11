str_unicode = "工业"
print("str_unicode:", type(str_unicode), ",", str_unicode)
str_utf8 = str_unicode.encode("utf8")
print("str_utf8:", type(str_utf8), ",", str_utf8)
