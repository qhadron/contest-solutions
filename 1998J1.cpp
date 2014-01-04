#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string s) {
    size_t a;
    vector<string>result;
    while(a=s.find(' '),a!=string::npos) {
        result.push_back(s.substr(0,a));
        s=s.substr(a+1);
    }
    if (s!=" ")
        result.push_back(s);
    return result;
};

int main() {
    int n;
    string s;
    vector<string> str;
    cin >> n;
    getline(cin,s);//remove garbage
    while (n--) {
        getline(cin,s);
        str=split(s);
        for (int i = 0; i < str.size();i++) {
            if (str[i].size()==4) {
                str[i]="****";
            }
            cout << str[i];
            if (i!=str.size()-1)
                cout << " ";
            else
                cout << endl;
        }

    }

}
