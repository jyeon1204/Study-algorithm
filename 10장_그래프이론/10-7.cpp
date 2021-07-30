#include <bits/stdc++.h>
using namespace std;

int v;
int indegree[501]; //진입차수 정보를 담을 배열
vector<int> graph[501]; //간선정보를 담을 연결리스트
int times[501]; //강의시간

void topologySort() {
	vector<int> result(501); //알고리즘 수행 결과를 담을 리스트
	for(int i=1; i<=v; i++)
		result[i] = times[i];	//result를 자기 자신으로 초기화함. 
	
	queue<int> q;
	
	for(int i=1; i<=v; i++)
		if(indegree[i] == 0)
			q.push(i);  //위상정렬에서 했던 것 처럼, 진입차수가 0인 수업을 큐에 넣는다. 
	
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0; i<graph[now].size();i++){
			result[graph[now][i]] = max(result[graph[now][i]], result[now]+times[graph[now][i]]); //현재의 시간보다 더 긴 강의가 있으면 그것으로 대체함.
			indegree[graph[now][i]] -= 1; //진입차수 1 줄이기 
			if(indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);  //진입차수가 0이 된 강의가 있다면 다시 큐에 삽입 
		}
	} 
	
	for(int i=1; i<=v; i++)
		cout<<result[i]<<endl;
	
} 

int main(void) {
    cin >> v;

    for (int i = 1; i <= v; i++) {
        // 첫 번째 수는 시간 정보를 담고 있음 
        int x;
        cin >> x;
        times[i] = x;
        // 해당 강의를 듣기 위해 먼저 들어야 하는 강의들의 번호 입력 
        while (true) {
            cin >> x;
            if (x == -1) break; //-1 입력시 다음줄로 넘어감 
            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }

    topologySort();
}
