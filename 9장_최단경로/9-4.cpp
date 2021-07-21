#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, start;
vector<pair<int, int> > graph[30001]; // 노드에 연결된 정보를 담기 위한 배열 
int d[30001]; //최단거리 테이블 

void dijkstra(int start){
	
	priority_queue<pair<int, int> > pq;
	//가장 경로가 짧은 노드를 구하기 위한 우선순위 큐 
	
	pq.push({0, start});
	d[start] = 0; // 시작노드를 우선순위큐와 거리 테이블에 넣는다.
	
	while(!pq.empty()) {
		int dist = -pq.top().first; // 가장 최단거리가 짧은 노드의 비용 -> 어차피 최장거리의 노드를 따로 구할 것이기 때문에, 수정할 필요 X 
		//C++에서 우선순위큐는 최대힙이기 때문에 음수를 붙여 저장하였음. 
		int now = pq.top().second; // 이 노드의 정보 
		pq.pop();
		
		if(d[now] < dist) continue; //이미 노드가 처리되었다는 뜻 (d[now]가 더 짧다)
		for(int i=0; i<graph[now].size(); i++){
			int cost = dist + graph[now][i].second;
			// cost = 현재 최단거리가 가장 짧은 노드의 비용 + 해당 노드로 가기 위한 비용
			if(cost < d[graph[now][i].first]){ // cost가 현재 노드로 가기 위한 원래의 비용보다 작다면 갱신 -> 최단거리 테이블과 우선순위 큐 모두에 반영 
				d[graph[now][i].first] = cost; 
				pq.push(make_pair(-cost, graph[now][i].first)); //d와 queue 모두 갱신, but queue에는 비용이 음수로 들어감. 
			} 
		} 	
	}
} //DIJKSTRA 알고리즘을 그대로 사용해도 무방한 문제였음.
 

int main(void){
	cin>>n>>m>>start;
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c}); //a 노드에서 b 노드로 가는데 c 만큼의 비용이 소요된다. 
	}
	
	fill(d, d+30001, INF); // d를 모두 INF로 초기화 
	
	dijkstra(start);
	
	//전보를 받을 수 있는 노드인 COUNT와 최장거리 MAX를 선언한다.  
	int count = 0;
	int max = 0;
  	for (int i = 1; i <= n; i++){
    	if(d[i] != INF){
    		count++;
    		if(d[i]>max) max = d[i]; //최댓값 갱신 
		}
    }
    
    cout<<count-1<<" "<<max; //COUNT에서 본인은 빼야 하므로 -1을 하였음(조건문에 명시하는 것 보다 연산이 줄어든다) 
    
} 
