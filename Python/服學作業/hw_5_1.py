str_list = input().split()
sum_list = [0]
for i in range(len(str_list)):
    sum_list.append(int(str_list[i]) + sum_list[i])
n = int(input())
for i in range(n):
    loc_list = input().split()
    loc_begin = int(loc_list[0])
    loc_end = int(loc_list[1])
    print(sum_list[loc_end] - sum_list[loc_begin - 1])