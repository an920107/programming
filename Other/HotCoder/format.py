import string


def format(filein:str, fileout:str) -> str:

    def last(s : str) -> str:
        return s[len(s) - 1]

    WORD = string.ascii_letters + string.digits + "_"
    SIGN = "=+-/*!&|%.:,><?^"
    BRACKET = "()}{]["

    result = []
    context = open(filein, "r").readlines()
    for line in context:
        if line[0] == "#":
            result.append(line)
            continue
        index = 0
        while index < len(line):
            if line[index] == " ":
                result.append(" ")
            elif line[index] in BRACKET:
                result.append(line[index])
            elif line[index] == ";":
                result.append(";")
            elif line[index] == "\"":
                for end in range(index + 1, len(line)):
                    if line[end] == "\"" and line[end - 1] != "\\":
                        result.append(line[index : end + 1])
                        index = end
                        break
            elif line[index] == "\'":
                if line[index + 1] == "\\":
                    result.append(line[index : index + 4])
                    index += 3
                else:
                    result.append(line[index : index + 3])
                    index += 2
            elif line[index] in WORD:
                for end in range(index, len(line)):
                    if line[end] not in WORD:
                        result.append(line[index : end])
                        index = end - 1
                        break
            elif line[index] in SIGN:
                for end in range(index, len(line)):
                    if line[end] not in SIGN:
                        result.append(line[index : end])
                        index = end - 1
                        break
                    
            index += 1
        result.append("\n")
    
    file_out = open(fileout, "w")
    for index in range(len(result) - 1):
        file_out.write(result[index])
        if result[index] != " " and result[index + 1] != " ":
            if last(result[index]) != "\n" and last(result[index + 1]) != "\n":
                file_out.write(" ")
