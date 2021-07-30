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
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
		parent[i] = i;
	
	for(int i=0; i<m; i++){
		int a, b,c;
		cin>>c>>a>>b;
		
		if(c==0)
			unionParent(a,b); 
		else
		{
			if(findParent(a)==findParent(b))
				cout<<"YES"<<endl;	// 한 줄에 하나씩 출력해야함.  
			else
				cout<<"NO"<<endl;
		}
	}
}
