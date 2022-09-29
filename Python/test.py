from random import randint
from functools import cmp_to_key

def pop_n(s : str) -> str:
    return s.strip("\n")

def cmd_cmp(x : str, y : str):
    if len(x) != len(y): return len(y) - len(x)
    return -1 if x < y else 1

cmd_list = list(map(pop_n, open("command_list.txt", "r", encoding="UTF-8").readlines()))
emoji_set = set(map(pop_n, open("emoji_list copy.txt", "r", encoding="UTF-8").readlines()))

cmd_list.sort(key=cmp_to_key(cmd_cmp))

while len(emoji_set) < len(cmd_list):
    emoji_set.add(list(emoji_set)[randint(0, len(emoji_set) - 1)] + list(emoji_set)[randint(0, len(emoji_set) - 1)])

dic = {cmd : emoji for (cmd, emoji) in zip(cmd_list, list(emoji_set)[:len(cmd_list)])}



file_out = open("out.cpp", "w", encoding="UTF-8")
file_in = open("in.cpp", "r", encoding="UTF-8")

for (key, val) in dic.items():
    file_out.write("#define " + val + " " + key + "\n")

context = map(pop_n, file_in.readlines())
for line in context:
    if line.find("#") >= 0:
        file_out.write(line + "\n")
    else:
        line_cp = line
        tmp_str = ""
        while bool(line_cp):
            flag = False
            if line_cp[0] in ["\t", " "]:
                line_cp = line_cp[1:]
                continue
            for (key, val) in dic.items():
                index = line_cp.find(key)
                if index == 0:
                    if bool(tmp_str):
                        file_out.write(tmp_str + " ")
                        tmp_str = ""
                    file_out.write(val + " ")
                    if (len(line_cp) == len(key)):
                        line_cp = ""
                    else:
                        line_cp = line_cp[len(key):]
                    flag = True
                    break
            if not flag:
                tmp_str += line_cp[0]
                line_cp = line_cp[1:]