#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

bool compare(int a, int b) {
    return a > b;
}
//������ �������� Ȥ�� ���������� �ƴ϶� Ư���� ���ؿ� ���� ������ �ϰ� ���� ���
//(���� ��� ���ڿ� vector�� ���ڿ��� 2��° ���ڿ� ���� ����) 
//������ ������ ���� �Լ��� �����Ͽ� ������ �� �ִ�

int main(void) {
    // N�� �Է¹ޱ�
    cin >> n;

    // N���� ������ �Է¹޾� ����Ʈ�� ����
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end(),compare); //vector�� ��,�� �ּҴ� v.begin, v.end�� ���ϱ� 
    
    for(int i=0; i<n; i++){
    	cout<<v.at(i)<<" ";
		//cout<<v[i]<<" "; 
	}
}
