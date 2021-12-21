'''
Assignment 06
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

def F(n):
    if (n >= 10): return 1 + F(n - 22) + F(F(n - 30) - 30)
    elif (n >= 5 and n < 10): return 2 + F(n - 2)
    else: return 3

def IsInputError(_str):
    for char in _str:
        if (not (ord(char) >= 48 and ord(char) <= 57)):
            return True
    if (int(_str) > 500): return True
    return False

while (True):
    input_str = input("Input a natural number: ")
    if (IsInputError(input_str)):
        print("Error!")
        continue
    if (input_str == "0"): break
    print(F(int(input_str)))