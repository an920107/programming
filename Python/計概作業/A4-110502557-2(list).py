'''
Assignment 04
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

file_r = open("score_110502557.txt", "r")
context_list = []
for line_str in file_r.readlines():
    context_list.append(line_str.split())
subject_str = input("查詢項目: ").capitalize()
name_str = input("姓名: ").capitalize()
for i in range(1, len(context_list)):
    if (context_list[i][0] == name_str):
        for j in range(1, len(context_list[0])):
            if (context_list[0][j] == subject_str):
                print(subject_str, name_str, context_list[i][j])
