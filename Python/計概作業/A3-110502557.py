'''
Assignment 03
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

def find_prime(num):
    if (num == 1): return False
    for i in range(2, num):
        if (num % i == 0): return False
    return True

def find_factor(num):
    factor_list = []
    for i in range(1, num + 1):
        if (num % i == 0): factor_list.append(i)
    return factor_list

f_input = open("test.txt", "r")
f_output = open("answer.txt", "w")
factor_list = []
num_list = f_input.read().split()
for i in range(len(num_list)):
    f_output.write("Number_" + str(i + 1) + ": " + str(int(num_list[i])) + "\n")
    factor_list = find_factor(int(num_list[i]))
    for j in range(len(factor_list)):
        f_output.write(str(factor_list[j]) + " ")
        f_output.write("Y\n" if find_prime(factor_list[j]) else "N\n")
    f_output.write("\n")
