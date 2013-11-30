#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool c(vector<string> st);
void print(vector<string> st,int i) {
    if (c(st)) {
        cout << st[i] << endl;
    }
}

int main() {
    string s;
    vector<string> st;
            int i = -1;
    while (true) {
        getline(cin,s);

        if (s == "QUIT")
            break;
        string command = s.substr(0,s.find(" "));
        string webpage = s.substr(s.find(" ")+1,(s.size()-command.size()));
        if (command == "VISIT") {
            st.push_back(webpage);
            i++;
            cout << st[i] << endl;
        }
        if (command == "BACK") {
                if (--i < st.size())
                cout << st[i] << endl;
                else
                cout << "Ignored" << endl;
        }
        if (command == "FORWARD") {
                if (++i < st.size()) {
                    cout << st[i] << endl;
                }
                else {
                    cout << "Ignored" << endl;
                }

        }
    }
}

bool c(vector<string> st) {
    cout << st.size() << endl;
    if (!st.empty())
        return true;
    else {
        cout << "Ignored" << endl;
        return false;
    }
}
