from format import format
import json


format("in.cpp", "out.cpp")


substitute_dict = dict(json.load(open("map.json")))

context = []
for line in open("out.cpp", "r").readlines():
    if line[0] == "#" or line.find(" ") < 0:
        context.append(line.strip("\n"))
        context.append("\n")
        continue
    context += line.strip("\n").split(" ")
    context.append("\n")


file_out = open("out.cpp", "w")

for key, value in substitute_dict.items():
    file_out.write("#define " + value + " " + key + "\n")
file_out.write("\n")

for s in context:
    new_s = substitute_dict.get(s)
    if new_s == None:
        file_out.write(s)
    else:
        file_out.write(new_s)
    if not bool(s) or s[len(s) - 1] != "\n":
        file_out.write(" ")