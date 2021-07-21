#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int, int> > graph[100001]; // ��忡 ����� ������ ��� ���� �迭 
int d[10001]; //�ִܰŸ� ���̺� 

void dijkstra(int start){
	
	priority_queue<pair<int, int> > pq;
	//���� ��ΰ� ª�� ��带 ���ϱ� ���� �켱���� ť 
	
	pq.push({0, start});
	d[start] = 0; // ���۳�带 �켱����ť�� �Ÿ� ���̺� �ִ´�.
	
	while(!pq.empty()) {
		int dist = -pq.top().first; // ���� �ִܰŸ��� ª�� ����� ���
		//C++���� �켱����ť�� �ִ����̱� ������ ������ �ٿ� �����Ͽ���. 
		int now = pq.top().second; // �� ����� ���� 
		pq.pop();
		
		if(d[now] < dist) continue; //�̹� ��尡 ó���Ǿ��ٴ� �� (d[now]�� �� ª��)
		for(int i=0; i<graph[now].size(); i++){
			int cost = dist + graph[now][i].second;
			// cost = ���� �ִܰŸ��� ���� ª�� ����� ��� + �ش� ���� ���� ���� ���
			if(cost < d[graph[now][i].first]){ // cost�� ���� ���� ���� ���� ������ ��뺸�� �۴ٸ� ���� -> �ִܰŸ� ���̺�� �켱���� ť ��ο� �ݿ� 
				d[graph[now][i].first] = cost; 
				pq.push(make_pair(-cost, graph[now][i].first)); //d�� queue ��� ����, but queue���� ����� ������ ��. 
				
			} 
		} 	
	}
}

int main(void){
	cin>>n>>m>>start;
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c}); //a ��忡�� b ���� ���µ� c ��ŭ�� ����� �ҿ�ȴ�. 
	}
	
	fill(d, d+10001, INF); // d�� ��� INF�� �ʱ�ȭ 
	
	dijkstra(start);
	
	for(int i=1; i<=n; i++){
		if(d[i]==INF)
			cout<<"INFINITY"<<endl;
		else
			cout<<d[i]<<endl;
	}
	
} 

