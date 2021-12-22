file_r = open("ans.txt", "r")
i = 0
result = ""
context = file_r.readlines()
for elm in context:
    i += 1
    result += elm.strip("\n")
    if (i % 5 == 0): result += "\n"
print(result)