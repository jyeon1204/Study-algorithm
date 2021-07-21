#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n,m;
int graph[501][501]; //�÷��̵��� �ִܰ�� �˰����� ��� ��忡�� ��� ������ �ִܰŸ��� ���ؾ� �ϹǷ� ������ �迭�� ����Ѵ�.  

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<501; i++)
		fill(graph[i], graph[i]+501, INF); // graph �ʱ�ȭ 
	
	for(int a=0; a<=n; a++)
		for(int b=0; b<=n; b++)
			if(a==b)
				graph[a][b] = 0; //���ο��� ���� �Ÿ��� 0��.  
	
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin >> a>> b>> c;
		graph[a][b] = c; //graph�� ������ �Է��Ѵ�.  
	}
	
	for(int k=1; k<=n; k++)
		for(int a=1; a<=n; a++)
			for(int b=1; b<=n; b++)
				graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b]); 
				//��ȭ���� �״�� �ڵ�� �Ű��. a->b �� �Ÿ����� a->k->b�� �Ÿ��� �� ������ �����Ѵٴ� ����. 
		
	
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

 
