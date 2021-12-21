'''
Assignment 04
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

def avg(int_list):
    return sum(int_list) / len(int_list)

file_r = open("score.txt", "r")
file_w = open("score_110502557.txt", "w")
file_w.write(file_r.readline())
context_list = []
for line_str in file_r.readlines():
    context_list.append(line_str.split())
score_dict = {str_list[0]: str_list[1:] for str_list in context_list}
for key_str, value_list in score_dict.items():
    file_w.write(key_str + " " + " ".join(value_list) + " " + str(avg(list(map(int, value_list)))) + "\n")
