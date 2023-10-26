words = input().split(" ")

word_count = dict()
for word in words:
    if word not in word_count.keys():
        word_count[word] = 0
    word_count[word] += 1

for word, count in word_count.items():
    print(f"[{word}]:{count}")
