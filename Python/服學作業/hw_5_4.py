n = int(input())
for i in range(n):
    result_str = ""
    line_str = input()
    for elm in line_str:
        result_str += str(ord(elm)) + "_"
    result_str = result_str[:len(result_str) - 1]
    print(result_str)