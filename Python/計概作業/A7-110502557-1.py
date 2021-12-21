'''
Assignment 07
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

result_str = ""
last_person = 0
max_length = 0
file_r = open("seat.txt", "r")
seat_str = file_r.readline()
seat_list = []
dist_list = []

# str 轉 list
for i in range(len(seat_str)):
    seat_list.append(ord(seat_str[i]) - 48)

# 每個位置與最近的人的距離
for i in range(len(seat_list)):
    if (seat_list[i] == 1):
        last_person = i
    dist_list.append(i - last_person)
seat_list.reverse()
dist_list.reverse()
last_person = 0
for i in range(len(seat_list)):
    if (seat_list[i] == 1):
        last_person = i
    dist_list[i] = min(dist_list[i], i - last_person)
seat_list.reverse()
dist_list.reverse()

# 考慮頭尾不為 1
if (seat_list[0] == 0):
    for i in range(len(seat_list)):
        if (seat_list[i] == 1):
            for j in range(i, -1, -1):
                dist_list[j] = i - j
            break
if (seat_list[len(seat_list) - 1] == 0):
    for i in range(len(seat_list) - 1, -1, -1):
        if (seat_list[i] == 1):
            for j in range(i, len(seat_list)):
                dist_list[j] = j - i
            break

# 整理、輸出
for i in range(len(dist_list)):
    max_length = max(max_length, dist_list[i])
result_str += "L = " + str(max_length) + "\ni ="
for i in range(len(dist_list)):
    if (dist_list[i] == max_length):
        result_str += " " + str(i)
print(result_str)
