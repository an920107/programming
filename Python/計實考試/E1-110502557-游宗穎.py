'''
Exam 01
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

while True:
    first_str = input()
    if (first_str == "stop"): break
    N = int(first_str)
    W = int(input())
    H = int(input())
    T = int(input())
    F = int(input())
    s = input()
    full_line = ""
    space_line = ""

    for w in range(W):
        full_line += s
    full_line *= N

    for t in range(T):
        space_line += s
    for spc in range(W - T * 2):
        space_line += " "
    for t in range(T):
        space_line += s
    space_line *= N

    for f in range(F):
        for t in range(T):
            print(full_line)
        for spc in range(H - T * 2):
            print(space_line)
        for t in range(T):
            print(full_line)
    
