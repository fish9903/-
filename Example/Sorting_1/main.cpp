#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	int kor;
	int eng;
	int math;
	string name;
	Student(int k, int e, int m, string n)
		:kor(k), eng(e), math(m), name(n) {}

	bool operator<(Student& s) {
		if (this->kor != s.kor)
			return this->kor > s.kor;
		if (this->eng != s.eng)
			return this->eng < s.eng;
		if (this->math != s.math)
			return this->math > s.math;
		return this->name < s.name;
	}
};

vector<Student> student;
int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k, e, m;
		string n;
		cin >> n >> k >> e >> m;
		student.push_back(Student(k, e, m, n));
	}
	sort(student.begin(), student.end());

	for (Student s : student)
		cout << s.name << '\n';

	return 0;
}