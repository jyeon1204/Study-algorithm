#include <bits/stdc++.h>
using namespace std;

int v;
int indegree[501]; //�������� ������ ���� �迭
vector<int> graph[501]; //���������� ���� ���Ḯ��Ʈ
int times[501]; //���ǽð�

void topologySort() {
	vector<int> result(501); //�˰��� ���� ����� ���� ����Ʈ
	for(int i=1; i<=v; i++)
		result[i] = times[i];	//result�� �ڱ� �ڽ����� �ʱ�ȭ��. 
	
	queue<int> q;
	
	for(int i=1; i<=v; i++)
		if(indegree[i] == 0)
			q.push(i);  //�������Ŀ��� �ߴ� �� ó��, ���������� 0�� ������ ť�� �ִ´�. 
	
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0; i<graph[now].size();i++){
			result[graph[now][i]] = max(result[graph[now][i]], result[now]+times[graph[now][i]]); //������ �ð����� �� �� ���ǰ� ������ �װ����� ��ü��.
			indegree[graph[now][i]] -= 1; //�������� 1 ���̱� 
			if(indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);  //���������� 0�� �� ���ǰ� �ִٸ� �ٽ� ť�� ���� 
		}
	} 
	
	for(int i=1; i<=v; i++)
		cout<<result[i]<<endl;
	
} 

int main(void) {
    cin >> v;

    for (int i = 1; i <= v; i++) {
        // ù ��° ���� �ð� ������ ��� ���� 
        int x;
        cin >> x;
        times[i] = x;
        // �ش� ���Ǹ� ��� ���� ���� ���� �ϴ� ���ǵ��� ��ȣ �Է� 
        while (true) {
            cin >> x;
            if (x == -1) break; //-1 �Է½� �����ٷ� �Ѿ 
            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }

    topologySort();
}
