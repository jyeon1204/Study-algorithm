#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n,m;
int graph[101][101]; 

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<101; i++)
		fill(graph[i], graph[i]+101, INF); // graph �ʱ�ȭ 
	
	for(int a=1; a<=n; a++)
		for(int b=1; b<=n; b++)
			if(a==b)
				graph[a][b] = 0; //���ο��� ���� �Ÿ��� 0��.  
	
	
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a>> b;
		graph[a][b] = 1; 
		graph[b][a] = 1;  //graph�� ������ �Է��Ѵ�. ���� �Է¿��� ����� �׷����̹Ƿ� a,b b,a ������ ��ο� �Է���.  
	}
	
	int x, k;
	cin>>x>>k;
	
	for(int p=1; p<=n; p++)
		for(int a=1; a<=n; a++)
			for(int b=1; b<=n; b++)
				graph[a][b] = min(graph[a][b], graph[a][p]+graph[p][b]); 
				//��ȭ���� �״�� �ڵ�� �Ű��. a->b �� �Ÿ����� a->k->b�� �Ÿ��� �� ������ �����Ѵٴ� ����. 
		
	
	int result = graph[1][k]+graph[k][x]; //1->k�� �Ÿ��� k->x �Ÿ��� ���Ѱ��� ��� 
	
	if(result >= INF)
		cout<<-1;
	else
		cout<<result;
}

 
