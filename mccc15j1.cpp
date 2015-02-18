#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
	cin >> s;
	if (s.length() == 3) {
		if (s == "416") {
			cin >> s;
			if (s.length() == 7) {
				cout << "valuable" << endl;
				return 0 ;
			}
		}
		else if (s == "437" || s == "647") {
			cin >> s;
			if (s.length() == 7) {
				cout << "valueless" << endl;
				return 0;
			}
		}
	}
	cout << "invalid" << endl;
}