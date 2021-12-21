count_dict = {chr(i): 0 for i in range(97, 123)}
line_str = input().lower()
for char in line_str:
    count_dict[char] += 1
max_char = ""
max_count = 0
for key, value in count_dict.items():
    if (value > max_count):
        max_count = value
        max_char = key
print(max_char)