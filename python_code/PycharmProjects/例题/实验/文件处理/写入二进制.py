import struct
a = "Hello"
b = 35
c = 89.46
binary1 = struct.pack('5sif', a.encode("UTF-8"), b, c)
with open("struct_file.dat", "wb")as sf:
    sf.write(binary1)
print("写入数据成功！")

with open("struct_file.dat", "rb")as sf1:
    binary2 = sf1.read()
a, b, c = struct.unpack('5sif', binary2)
print("a:", a.decode("UTF-8"))
print("b:", b)
print("c:%.2f" % c)
