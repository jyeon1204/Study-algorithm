#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main(void){
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	} //ȭ�� ��� �ޱ� 
	
	vector<int> d(m + 1, 10001); //��ȭ���� ���� �迭�� vector�� ���� 
	
	d[0] = 0; //0�� ȭ��� ���� �� ����
	 
	for(int i=0; i<n; i++)
	{
		for(int j=arr[i]; j<=m; j++) 
			d[j] = min(d[j], d[j-arr[i]]+1); 
			//j-arr[i]�� �ϴ� ������ ȭ�� ������ŭ �� �ݾ׿���, ȭ�� �ϳ� ���ϱ⸸ �ϸ� �Ǳ� ������. �̸� d[j]�� ���Ͽ� �ּҰ��� d[j]�� ������. 
			//�̸� i<n ���� �����ϹǷ�, ȭ�� ������ ������ŭ �ݺ��ϸ鼭 d�� ������ �����ϴ� ����. 
			//��ȭ��: ai = min(a(k-1)+1, ai) 
		
	}
	
	if(d[m] == 10001)
		cout<<-1;
	else
		cout<<d[m];
	
}
