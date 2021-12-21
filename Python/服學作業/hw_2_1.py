n = int(input())

for i in range(n):
    m = int(input())
    if m >= 2 and m <= 4:
        print("spring")
    elif m >= 5 and m <= 7:
        print("summer")
    elif m >= 8 and m <= 10:
        print("autumn")
    elif m == 11 or m == 12 or m == 1:
        print("winter")
    else:
        print("error")