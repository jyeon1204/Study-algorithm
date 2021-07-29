#include <bits/stdc++.h>
using namespace std;

int v,e;
int indegree[100001]; //���������� ����� �迭  
vector<int> graph[100001]; //�׷��� ������ ���� ���� 

void topologySort(){
	vector<int> result;	//���ĵ� ����� ������ vector 
	queue<int> q;	//��������0�� ��带 ���� ť 
	
	for(int i=1; i<=v; i++)
		if(indegree[i] == 0)
			q.push(i); //�������� 0�� ��带 ť�� �����Ѵ�.  
	
	while(!q.empty()){
		int now = q.front(); //ť�� �� �տ� �ִ� ��带 ������. 
		q.pop();
		
		result.push_back(now); //����� ������ ���Ϳ� ���� ��带 �����Ѵ�.  
		
		for(int i=0; i<graph[now].size(); i++){
			indegree[graph[now][i]] -= 1; //����� ����� ���������� 1�� ���δ�. 
			if(indegree[graph[now][i]]==0) //���������� 0�� �� ������ ť�� �����Ѵ�.  
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

