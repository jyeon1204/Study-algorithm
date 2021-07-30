#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[100001];
vector<pair<int, pair<int, int> > > edges; //간선의 정보가 들어가는 vector 
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
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
		parent[i] = i;
	
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back({c, {a, b}}); 
	}
	
	sort(edges.begin(), edges.end());
	int last = 0; //마을을 두개로 분리시키기 위해 간선 하나를 뺄 건데, 제일 크기가 큰 간선을 빼는 것이 이득이다.  
	
	for(int i=0; i< edges.size(); i++){
		int c = edges[i].first;	//간선의 비용 
		int a = edges[i].second.first; //노드 1 
		int b = edges[i].second.second; //노드 2 
		
		if(findParent(a)!=findParent(b)){ //두 노드가 같은 집합이 아닐 경우에만 union하고 비용을 더함.  
			unionParent(a,b);
			result += c;
			last = c;
		}		
	}
	
	cout<<result-last;
	
}
