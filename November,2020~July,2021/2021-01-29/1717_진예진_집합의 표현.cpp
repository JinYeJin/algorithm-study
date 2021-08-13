/*
백준 1717 집합의 표현
2021-01-22/1197_김기홍_최소스패닝트리.py 참고함
# union-find
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int parent[1000001];

int find_parent(int idx){
	if(parent[idx] == idx) return idx;
	return parent[idx] = find_parent(parent[idx]);
}

void union_set(int a, int b){
	int a_parent = find_parent(a);
	int b_parent = find_parent(b);
	if(a_parent < b_parent) parent[b_parent] = a_parent;
    else parent[a_parent] = b_parent;
}


int main(void){
    FILE *stream = freopen("S2\\30\\input\\1717.txt", "r", stdin);
    if(!stream) perror("freopen");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	int N, M; 
	cin >> N >> M;
	
	for(int i = 0; i <= N; i++){
		parent[i] = i;
	}

    for(int m = 0; m < M; m++){
		int command, a, b;

		cin >> command >> a >> b;

		if(command == 0) union_set(a, b);
		else{
			if (find_parent(a) == find_parent(b))
                cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
