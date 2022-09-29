import string

def strip_n(s : str) -> str:
    return s.strip("\n")

emoji_list = map(strip_n, open("emoji_list.txt", "r"))

context = open("in.cpp", "r").readlines()
file_out = open("out.cpp", "w")

ALPHAS = string.ascii_letters + string.digits + "_\"\'\\"
SPECIAL = "()[]}{"
for line in context:
    if line[0] == "#":
        file_out.write(line)
        continue
    ch_type = 0
    for ch in line:
        if ch == " " or ch == "\t" or ch == "\n":
            ch_type = 0
        elif ch in ALPHAS:
            if ch_type == 2:
                file_out.write(" ")
            ch_type = 1
        else:
            if ch_type == 1:
                file_out.write(" ")
            ch_type = 2
        file_out.write(ch)
