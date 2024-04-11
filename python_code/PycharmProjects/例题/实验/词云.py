from wordcloud import WordCloud
import jieba

with open(r"C:\Users\23947\Desktop\text.txt", "r") as f:
    allSentence = f.read()
print(allSentence)
#
# with open("word.txt", "w") as f:
#     for i in allSentence:
#         f.write(str(i) + " ")

# with open("word.txt", "r") as f:
#     allSentence = f.read()


word = WordCloud(background_color="white", width=1342,
                 font_path=r"E:\工作\学校\技术部\字体\PangMenZhengDaoCuShuTi-2.ttf",
                 height=873, min_font_size=16, max_font_size=200, max_words=999).generate(allSentence)
word.to_file('词云3.png')
