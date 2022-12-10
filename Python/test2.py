count_dict = {
    "網頁美工組": 0,
    "行銷企劃組": 0,
    "影音媒體組": 0,
    "程式設計組": 0
}

file = open("Python/in.tsv", "r")
lines = file.readlines()
for line in lines[1:]:
    data = line.split("\t")
    order = int(data[4].strip("\n"))
    # print(order)
    for group in data[:order]:
        # print(group)
        count_dict[group] += 1

print(f"\nTotal {len(lines) - 1}")
for (key, val) in count_dict.items():
    print(key, val)
