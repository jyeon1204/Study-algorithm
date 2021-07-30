#include <bits/stdc++.h>
using namespace std;

int v,e;
int parent[100001];

int findParent(int x){
	if(x == parent[x]) return x; 	//����� ��Ʈ�� �����̸� �ٷ� return��. 
	return parent[x] = findParent(parent[x]); //����� ��Ʈ�� ������ �ƴϸ� ��Ʈ��尡 ���� �� ���� �Ž����ö� 
}

void unionParent(int a, int b){
	a = findParent(a);
	b = findParent(b);
	if(a<b)		//���� ��尡 ��Ʈ�� �ȴ�. 
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
				cout<<"YES"<<endl;	// �� �ٿ� �ϳ��� ����ؾ���.  
			else
				cout<<"NO"<<endl;
		}
	}
}
