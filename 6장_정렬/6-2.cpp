#include <bits/stdc++.h>
using namespace std;

//���� ���̺귯���� ������� �ʰ� student ����ü�� �������. 
class student {
	public: 
		string name;
		int score;
		student(string name, int score){
			this->name = name;
			this->score = score;
		}
		 bool operator <(student &other) {  //���ؿ����ڸ� �������. ��ü���� ���ϴ� ������ ������ ����  
        return this->score < other.score; 
    	}
};

int n;
vector<student> v;

int main(void){
	cin>>n;
	
	for(int i=0; i<n; i++){
		int x;
		string s;
		cin>>s>>x;
		v.push_back(student(s,x));
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++)
		cout<<v[i].name<<" ";
	
}
