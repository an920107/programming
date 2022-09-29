import string


def format(filein:str, fileout:str) -> str:

    WORD = string.ascii_letters + string.digits + "_"
    SIGN = "=+-/*!&|%.:;,><}{)(][?^\n\t"

    result = []
    context = open(filein, "w").readlines()
    for line in context:
        index = 0
        while index < len(line) - 1:

            index += 1