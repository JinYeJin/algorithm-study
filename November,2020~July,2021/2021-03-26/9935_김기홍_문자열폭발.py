sentence = input()
bomb = input()

last = bomb[-1]
length = len(bomb)
st = []

for ch in sentence:
    st.append(ch)
    if ch == last:
        if ''.join(st[-length:]) == bomb:
            # st = st[ : -length]
            del st[-length:]

if st:
    print(''.join(st))
else:
    print("FRULA")
