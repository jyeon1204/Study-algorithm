#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n,m;
int graph[501][501]; //플루이드의 최단경로 알고리즘은 모든 노드에서 모든 노드로의 최단거리를 구해야 하므로 이차원 배열을 사용한다.  

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<501; i++)
		fill(graph[i], graph[i]+501, INF); // graph 초기화 
	
	for(int a=0; a<=n; a++)
		for(int b=0; b<=n; b++)
			if(a==b)
				graph[a][b] = 0; //본인에게 가는 거리는 0임.  
	
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin >> a>> b>> c;
		graph[a][b] = c; //graph에 정보를 입력한다.  
	}
	
	for(int k=1; k<=n; k++)
		for(int a=1; a<=n; a++)
			for(int b=1; b<=n; b++)
				graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b]); 
				//점화식을 그대로 코드로 옮겼다. a->b 의 거리보다 a->k->b의 거리가 더 가까우면 갱신한다는 개념. 
		
	
	for(int a=1; a<=n; a++){
		for(int b=1; b<=n; b++){
			if(graph[a][b] == INF)
				cout<<"INFINITY ";
			else
				cout<<graph[a][b]<<" ";
		}
		cout<<endl;
	}
}

 
