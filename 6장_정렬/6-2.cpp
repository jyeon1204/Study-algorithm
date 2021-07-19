#include <bits/stdc++.h>
using namespace std;

//따로 라이브러리를 사용하지 않고 student 구조체를 만들었음. 
class student {
	public: 
		string name;
		int score;
		student(string name, int score){
			this->name = name;
			this->score = score;
		}
		 bool operator <(student &other) {  //기준연산자를 만들었음. 객체끼리 비교하는 기준은 각각의 점수  
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
