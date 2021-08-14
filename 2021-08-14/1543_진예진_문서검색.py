import sys
sys.stdin = open("input/1543.txt")

doc = input()
query = input()
dlen = len(doc)
qlen = len(query)

count = 0
start = 0
limit = dlen - qlen

# print(True if "a b " == "a b" else False)

while start <= limit:
# for index in range(dlen - qlen):
    end = start+qlen
    # print(doc[start:end])
    # print("start", start)
    # break
    if doc[start:end] == query:
        # print("same", doc[start:end], query)
        count += 1
        start = end
        # print("start", start, "end", end)
    else:
        start += 1
        # print("not", start)
    # print()

print(count)
