'''
Exam 02
Name: 游宗穎
Student Number: 110502557
Course: 2021-CE1001A
'''

file_r = open("invoice.txt", "r")
invoice_list = file_r.readlines()
for i in range(len(invoice_list)):
    invoice_list[i] = invoice_list[i].strip("\n")
file_r.close()
file_r = open("num.txt", "r")
extreme_str = file_r.readline().strip("\n")
special_str = file_r.readline().strip("\n")
normal_list = []
normal_list.append(file_r.readline().strip("\n"))
normal_list.append(file_r.readline().strip("\n"))
normal_list.append(file_r.readline().strip("\n"))
extend_list = []
extend_list.append(file_r.readline().strip("\n"))
extend_list.append(file_r.readline().strip("\n"))
extend_list.append(file_r.readline().strip("\n"))
file_r.close()

prise_list = [0 for i in range(9)]
tmp_list = invoice_list.copy()
for i in range(len(invoice_list)):
    if (invoice_list[i] == extreme_str):
        prise_list[0] += 1
        tmp_list.pop(i)
invoice_list = tmp_list.copy()
for i in range(len(invoice_list)):
    if (invoice_list[i] == special_str):
        prise_list[1] += 1
        tmp_list.pop(i)
invoice_list = tmp_list.copy()
for k in range(5):
    for i in range(len(invoice_list)):
        if (invoice_list[i] in normal_list):
            prise_list[k + 2] += 1
            tmp_list.pop(i)
    for i in range(len(tmp_list)):
        tmp_list[i] = tmp_list[i][1:]
    for i in range(len(normal_list)):
        normal_list[i] = normal_list[i][1:]
    invoice_list = tmp_list.copy()
extend_list.extend(normal_list)
for i in range(len(invoice_list)):
    if (invoice_list[i] in extend_list):
        prise_list[7] += 1
        tmp_list.pop(i)
invoice_list = tmp_list.copy()
for i in range(len(invoice_list)):
    prise_list[8] += 1

print("特別獎:", prise_list[0])
print("特獎:", prise_list[1])
print("頭獎:", prise_list[2])
print("二獎:", prise_list[3])
print("三獎:", prise_list[4])
print("四獎:", prise_list[5])
print("五獎:", prise_list[6])
print("六獎:", prise_list[7])
print("沒中獎:", prise_list[8])
print(10000000 * prise_list[0] + 2000000 * prise_list[1] + 200000 * prise_list[2] + 40000 * prise_list[3] + 10000 * prise_list[4] + 4000 * prise_list[5] + 1000 * prise_list[6] + 200 * prise_list[7])
