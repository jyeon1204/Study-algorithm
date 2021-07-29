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
	
	cin>>v>>e;
	
	for(int i=1; i<=v; i++){
		parent[i] = i;	//����� ��Ʈ��� ���̺��� �ʱ�ȭ�Ѵ�. 
	}
	
	for(int i=0; i<e; i++){
		int a, b;
		cin >> a>>b;
		unionParent(a,b); 
	}
	
	cout<<"�� ���Ұ� ���� ����: ";
	for(int i=1; i<=v; i++)
		cout<<findParent(i)<<" "; 
	cout<<endl;
	
	cout<<"�θ� ���̺�: ";
	for(int i=1; i<=v; i++)
		cout<<parent[i]<<" ";
	cout<<endl;
	
}
