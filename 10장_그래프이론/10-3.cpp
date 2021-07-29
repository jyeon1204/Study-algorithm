#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];
vector<pair<int, pair<int, int> > > edges; //������ ������ ���� vector 
int result = 0;

int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void){
	cin>>v>>e;
	
	for(int i=1; i<=v; i++)
		parent[i] = i;
	
	for(int i=0; i<e; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({c, {a, b}}); 
	}
	
	sort(edges.begin(), edges.end());
	
	for(int i=0; i< edges.size(); i++){
		int c = edges[i].first;	//������ ��� 
		int a = edges[i].second.first; //��� 1 
		int b = edges[i].second.second; //��� 2 
		
		if(findParent(a)!=findParent(b)){ //�� ��尡 ���� ������ �ƴ� ��쿡�� union�ϰ� ����� ����.  
			unionParent(a,b);
			result += c;
		}		
	}
	
	cout<<result;
	
}
