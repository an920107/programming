def solve(s: str, n: int, u: int, l: int) -> str:
    new_s = ""
    for ch in s:
        ch_ord = ord(ch)
        if 48 <= ch_ord <= 57:
            ch_ord += n
            if ch_ord < 48: ch_ord += 10
            elif ch_ord > 57: ch_ord -= 10
        elif 65 <= ch_ord <= 90:
            ch_ord += u
            if ch_ord < 65: ch_ord += 26
            elif ch_ord > 90: ch_ord -= 26
        elif 97 <= ch_ord <= 122:
            ch_ord += l
            if ch_ord < 97: ch_ord += 26
            elif ch_ord > 122: ch_ord -= 26
        new_s += chr(ch_ord)
    return new_s

s = input()
lst = list(map(int, input().split(" ")))
print(solve(s, lst[0], lst[1], lst[2]))