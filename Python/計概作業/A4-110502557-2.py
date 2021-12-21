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
score_dict = {context_list[i][0]: {context_list[0][j]: context_list[i][j] for j in range(1, len(context_list[0]))} for i in range(1, len(context_list))}
subject_str = input("查詢項目: ").capitalize()
name_str = input("姓名: ").capitalize()
print(name_str, subject_str, score_dict[name_str][subject_str])
