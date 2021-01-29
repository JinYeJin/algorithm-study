import sys
from collections import defaultdict

# 트라이를 저장할 노드 => 각 문자의 노드 a p p l e
class TrieNode:
    def __init__(self):
        self.word = False
        self.children = defaultdict(TrieNode)


# 트라이 연산을 구현할 별도 클래스
class Trie:
    def __init__(self):
        # 별도의 TrieNode 클래스 가짐
        self.root = TrieNode()

    # 삽입 메소드
    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            node = node.children[char]
        # 단어가 모두 완성되었을 때만 True 리턴
        # children과 같은 depth의 word에 True 지정
        node.word = True

    # 해당 단어로 시작하는 단어가 존재하는지 여부
    # 이미 넣을때 끝나는 지점에 True로 되어있기 때문에 True 리턴
    def search(self, prefix: str) -> bool:
        node = self.root
        for index, char in enumerate(prefix):
            if node.word is True:
                return False
            node = node.children[char]
        return True

tc = int(input())
for _ in range(tc):
    n = int(input())
    t = Trie()
    f = True
    n_list = list()
    for _ in range(n):
        num = input()
        n_list.append(num)
        t.insert(num)
    for num in n_list:
        ch = t.search(num)
        if ch is False:
            f = False
            print("NO")
            break
    if f is True:
        print("YES")
