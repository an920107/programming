'''
Assignment 07
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

tmp_list = []
result_list = [""]
result_str = ""
file_r = open("digit.txt", "r")
file_w = open("110502557.txt", "w", encoding = "utf-8")
num_str = file_r.readline()
num_dict = {
    "2": ("a", "b", "c"),
    "3": ("d", "e", "f"),
    "4": ("g", "h", "i"),
    "5": ("j", "k", "l"),
    "6": ("m", "n", "o"),
    "7": ("p", "q", "r", "s"),
    "8": ("t", "u", "v"),
    "9": ("w", "x", "y", "z")}

if (num_str == "1"):
    result_str += "none"
else:
    for i in range(len(num_str)):
        tmp_list = [x + y for x in result_list for y in num_dict[num_str[i]]]
        result_list = list(set(tmp_list))
    result_list.sort()
    for i in range(len(result_list)):
        result_str += result_list[i] + " "

print(result_str)
file_w.write(result_str + "\n110502557游宗穎")
