'''
Practice 06
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1003-B
'''

def DigitSum(n):
    n_sum = 0
    while (n > 0):
        n_sum += n % 10
        n //= 10
    return n_sum

def F(n):
    if (n <= 0): return 0
    elif (n % 2 == 0): return 2 + F(n // 2)
    else: return 3 + F(DigitSum(n) - 5)

file_r = open("test.txt", "r")
context_list = file_r.readlines()
for line_str in context_list:
    print(F(int(line_str.strip("\n"))))
