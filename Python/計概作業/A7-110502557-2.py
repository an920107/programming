'''
Assignment 07
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

result_str = ""
result_list = [["()"]]
file_r = open("num.txt", "r")
file_w = open("110502557.txt", "w", encoding = "utf-8")
num = int(file_r.readline())

if (num == 0):
    result_str += "none"
else:
    for i in range(1, num):
        result_list.append([])
        for j in range(len(result_list[i - 1])):
            result_list[i].append("(" + result_list[i - 1][j] + ")")
        for j in range(i):
            result_list[i] += [x + y for x in result_list[j] for y in result_list[i - j - 1]]
        result_list[i] = list(set(result_list[i]))
    for i in range(len(result_list[num - 1])):
        result_str += result_list[num - 1][i] + " "

print(result_str)
file_w.write(result_str + "\n110502557游宗穎")
