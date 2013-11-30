#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main () {
    string s;
    while (getline(cin,s),s!=""){
        stack<char> st;
        bool b = true;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '{')
                st.push('{');
                            if (s[i] == '[')
                st.push('[');
                            if (s[i] == '(')
                st.push('(');
            if (s[i] == '}') {
                if (!st.empty()) {
                    if (st.top() != '{') {
                        b = false;
                        break;
                    } else {
                        st.pop();
                    }
                } else {
                    b = false;
                    break;
                }
            }

            if (s[i] == ']') {
                if (!st.empty()) {
                    if (st.top() != '[') {
                        b = false;
                        break;
                    } else {
                        st.pop();
                    }
                } else {
                    b = false;
                    break;
                }
            }

            if (s[i] == ')') {
                if (!st.empty()) {
                    if (st.top() != '(') {
                        b = false;
                        break;
                    } else {
                        st.pop();
                    }
                } else {
                    b = false;
                    break;
                }
            }

        }

        if (!st.empty())
            b = false;
        if (b)
            cout << "Balance" << endl;
        else
            cout << "Unbalance" << endl;
    }

}

/*
int main() {
    string s;
    while(getline(cin,s), s !=""){
        stack<char> st;
        bool isbalanced = true;
        for (int i = 0; i < s.length(); i++){
            cout << i<< endl;
            if (isbalanced)
            switch(s[i]) {
                case '[':
                st.push('[');
                case '{':
                st.push('{');
                case '(':
                st.push('(');
                case ')':
                while (st.top() != '('){
                       if (!st.empty())
                       st.pop();
                       else{
                       isbalanced = false;
                       break;
                       }
                }
                case ']': {
                    while (st.top() != '['){
                       if (!st.empty())
                       st.pop();
                       else
                       isbalanced = false;
                       break;
                }
                case '}' :
                while (st.top() != '{'){
                       if (!st.empty())
                       st.pop();
                       else
                       isbalanced = false;
                       break;
                }
                }
            }}
            if (isbalanced)
                cout << "Balance" << endl;
            else
                cout << "Unbalance" << endl;
        }
    }
*/
