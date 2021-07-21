#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n,m;
int graph[101][101]; 

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<101; i++)
		fill(graph[i], graph[i]+101, INF); // graph 초기화 
	
	for(int a=1; a<=n; a++)
		for(int b=1; b<=n; b++)
			if(a==b)
				graph[a][b] = 0; //본인에게 가는 거리는 0임.  
	
	
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a>> b;
		graph[a][b] = 1; 
		graph[b][a] = 1;  //graph에 정보를 입력한다. 현재 입력에선 양방향 그래프이므로 a,b b,a 순서쌍 모두에 입력함.  
	}
	
	int x, k;
	cin>>x>>k;
	
	for(int p=1; p<=n; p++)
		for(int a=1; a<=n; a++)
			for(int b=1; b<=n; b++)
				graph[a][b] = min(graph[a][b], graph[a][p]+graph[p][b]); 
				//점화식을 그대로 코드로 옮겼다. a->b 의 거리보다 a->k->b의 거리가 더 가까우면 갱신한다는 개념. 
		
	
	int result = graph[1][k]+graph[k][x]; //1->k의 거리와 k->x 거리를 더한것이 결과 
	
	if(result >= INF)
		cout<<-1;
	else
		cout<<result;
}

 
