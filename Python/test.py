file = open("info.csv", "a")
for i in range(10):
    str = input()
    while (str.count(":") > 0):
        str = str.replace(":", "：")
    while (str.count(" ") > 0):
        str = str.replace(" ", "")
    str = str[str.find("：") + 1:].strip("\n")
    file.write(str + ",")
file.write(",\n")

# for i in range(10):
#     file.write(input() + ",")
# file.write("\n")