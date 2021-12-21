n = int(input())
for i in range(n):
    str_list = input().split()
    a = int(str_list[0])
    b = int(str_list[1])
    c = int(str_list[2])
    if (a == 1):
        print(b + c)
    elif (a == 2):
        print(b - c)
    elif (a == 3):
        print(b * c)
    elif (a == 4):
        print(b // c)