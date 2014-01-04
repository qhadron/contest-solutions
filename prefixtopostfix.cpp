#include <iostream>
#include <string>
#include <algorithm>

/*
    NOT FINISHED
    basic idea -- 1. find operator
                  2. find operand 1
                    a. loop until operand 1 is a number
                  3. find operand 2
                    b. loop until operand 2 is a number
                  4. print operand 1
                  5. print operand 2
                  6. print operator
*/


using namespace std;

void get_operator(string str);
string get_data(string str);

string rest;
string prefix;
int main() {

    getline(cin,prefix);

    while (prefix != "0")
    {
        rest = prefix;
        get_operator(prefix);
        printf("\n");
        getline(cin,prefix);
    }

    return 0;
}


void get_operator(string str) {
    string data1, data2;
    if ((str[0]=='+')||(str[0]=='-')) {
        data1=getdata(str.substr(2));
        if (data1!="") {
            cout << data1[0] << " ";
            if (data1.size() >= 2)
                rest =data1.substr(2);
            data2=get_data(rest);
        }
        else {
            data2 = get_data(str);
        }

        if (data2!="") {
            cout << data2[0] << " ";
            if (data2.size >= 2)
                rest = data2.substr(2);
        }
        cout << str[0] <<  " ";
    }
    else  {
        cout << str[0] << " ";
    }
}

string get_data(string str) {
    if ((str[0]=="+")||(str[0]=="-")) {
         get_operator(str);
         return "";
    }
    else
        return str;
}
