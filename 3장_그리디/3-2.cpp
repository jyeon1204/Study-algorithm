#include <iostream>
using namespace std; 
//ū ���� ��Ģ 

int n, m, k;
vector<int> v;

int main() {
    // N, M, K�� ������ �������� �����Ͽ� �Է� �ޱ�
    cin >> n >> m >> k;

    // N���� ���� ������ �������� �����Ͽ� �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // �Է� ���� ���� �����ϱ�
    int first = v[n-1];
    int second = v[n-2];
	int result = 0;
	
	int count = (m/(k+1))*k;
	count += m % (k+1);
	
	result = first*count;
	result += (m-count)*second;
	
	
	cout<<result<<endl;
    
    
    
}
