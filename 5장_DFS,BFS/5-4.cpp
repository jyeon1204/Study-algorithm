#include <bits/stdc++.h> 
using namespace std;

// 미로찾기 
// 모든 노드에 각각의 최단 경로를 모두 기록하는 방식 

int n, m;
int graph[201][201];

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y){
	//queue 라이브러리를 활용하여 맵 정보 저장 
	queue<pair<int, int> > q;
	q.push({x,y});
	
	while(!q.empty()){
		//큐의 맨 앞에 있는 좌표 가져오기 
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){ //상하좌우 4방향의 좌표를 구해 확인 
			int nx = x + dx[i]; 
			int ny = y + dy[i];
			
			//미로 공간을 벗어난 경우 
			if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
			// 막혀있을 경우  
			if(graph[nx][ny] ==0) continue;
			// graph == 1이면 처음 방문하는 노드, 처음 방문하는 노드에 한해 기록 
			if(graph[nx][ny] == 1){
				graph[nx][ny] = graph[x][y] + 1;
				q.push({nx,ny});
			}
		}
	}
	return graph[n-1][m-1];
}

int main(void) {
    // N, M을 공백을 기준으로 구분하여 입력 받기
    cin >> n >> m;
    // 2차원 리스트의 맵 정보 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    // BFS를 수행한 결과 출력
    cout << bfs(0, 0) << '\n';
    return 0;
}

