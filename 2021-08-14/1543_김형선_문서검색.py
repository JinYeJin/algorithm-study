text = input()
query = input()

count = 0
i = 0
while i < len(text):
    if (text[i:i+len(query)] == query):
        count += 1
        i += len(query)
    else:
        i += 1
print(count)
