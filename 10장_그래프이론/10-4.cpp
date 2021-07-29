#include <bits/stdc++.h>
using namespace std;

int v,e;
int indegree[100001]; //진입차수를 기록할 배열  
vector<int> graph[100001]; //그래프 정보를 담을 벡터 

void topologySort(){
	vector<int> result;	//정렬된 결과를 보여줄 vector 
	queue<int> q;	//진입차수0인 노드를 넣을 큐 
	
	for(int i=1; i<=v; i++)
		if(indegree[i] == 0)
			q.push(i); //진입차수 0인 노드를 큐에 삽입한다.  
	
	while(!q.empty()){
		int now = q.front(); //큐의 맨 앞에 있는 노드를 꺼낸다. 
		q.pop();
		
		result.push_back(now); //결과를 보여줄 벡터에 현재 노드를 삽입한다.  
		
		for(int i=0; i<graph[now].size(); i++){
			indegree[graph[now][i]] -= 1; //연결된 노드의 진입차수를 1씩 줄인다. 
			if(indegree[graph[now][i]]==0) //진입차수가 0이 된 노드들은 큐에 삽입한다.  
				q.push(graph[now][i]);
		}
	}
	
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
}

int main(void){
	cin>>v>>e;
	
	for(int i=0; i<e; i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		indegree[b] += 1;

	}
	
	topologySort();
	
}

