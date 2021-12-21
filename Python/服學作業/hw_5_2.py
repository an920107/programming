n = int(input())
for run in range(n):
    result_list = []
    line_str = input()
    for i in range(len(line_str)):
        if (line_str not in result_list):
            result_list.append(line_str)
        tmp = line_str[1:]
        line_str = tmp + line_str[0]
    for elm in result_list:
        print(elm)