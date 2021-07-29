#include <bits/stdc++.h>
using namespace std;

int v,e;
int parent[100001];

int findParent(int x){
	if(x == parent[x]) return x; 	//노드의 루트가 본인이면 바로 return함. 
	return parent[x] = findParent(parent[x]); //노드의 루트가 본인이 아니면 루트노드가 나올 때 까지 거슬러올라감 
}

void unionParent(int a, int b){
	a = findParent(a);
	b = findParent(b);
	if(a<b)		//작은 노드가 루트가 된다. 
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void){
	
	cin>>v>>e;
	
	for(int i=1; i<=v; i++){
		parent[i] = i;	//노드의 루트노드 테이블을 초기화한다. 
	}
	
	for(int i=0; i<e; i++){
		int a, b;
		cin >> a>>b;
		unionParent(a,b); 
	}
	
	cout<<"각 원소가 속한 집합: ";
	for(int i=1; i<=v; i++)
		cout<<findParent(i)<<" "; 
	cout<<endl;
	
	cout<<"부모 테이블: ";
	for(int i=1; i<=v; i++)
		cout<<parent[i]<<" ";
	cout<<endl;
	
}
