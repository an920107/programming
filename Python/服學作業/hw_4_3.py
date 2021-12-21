t = int(input())
for count in range(t):
    word_str = input()
    password_str = ""
    for i in range(1, len(word_str)):
        password_str += str(abs(ord(word_str[i]) - ord(word_str[i - 1])))
    print(password_str)