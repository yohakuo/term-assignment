import operator
str1 = "superman"
str2 = "monster"
print("'superman'<monster':", operator.lt(str1, str2))
print("'superman'<=monster':", operator.le(str1, str2))
print("'superman'==monster':", operator.eq(str1, str2))
print("'superman'!=monster':", operator.ne(str1, str2))
print("'superman'>monster':", operator.ge(str1, str2))
print("'superman'>=monster':", operator.gt(str1, str2))
