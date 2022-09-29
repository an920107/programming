file = open("emoji_list.txt", "w")
for i in range(65, 91):
    file.write(chr(i) + "\n")
