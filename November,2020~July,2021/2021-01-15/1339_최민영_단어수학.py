n = int(input())
data = list()
for _ in range(n):
    e = input()
    data.append(e)
total = dict()
for ele in data:
    for i in range(len(ele)):
        dec = 10 ** (len(ele) - i - 1)
        if ele[i] in total:
            total[ele[i]] += dec
        else:
            total[ele[i]] = dec
num_list = sorted(total.items(), key=lambda x: x[1], reverse=True)
# num_list = sorted(total.values(), reverse=True)
init_count = 9
sum = 0
for i in num_list:
    # sum += i* init_count
    sum += i[1] * init_count
    init_count -= 1
print(sum)
