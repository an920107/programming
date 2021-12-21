t = int(input())
for count in range(t):
    sample_str = input()
    compare_str = input()
    min_len = min(len(sample_str), len(compare_str))
    same_int = 0
    for i in range(min_len):
        if (sample_str[i] == compare_str[i]):
            same_int += 1
    if (same_int == 0):
        print("wrong")
    else:
        print(same_int)