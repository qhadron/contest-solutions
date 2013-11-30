#include <iostream>
#include <stack>
using namespace std;

int main() {
    int a [1009],i,n;
    stack<int> sk;
    whie (cin>>n,n!=0){

        while (cin>>a[1],a[1]!=0){
            for (i=2;i<=n;i++)
            cin >>a[i];
            int temp = 1;
            for (i = 1; i<=n;i++){
            if ((!sk.empty()&&sk.top()==a[i]))
            sk.pop();
            else if(a[i]<temp)
                break;
            else {
                for (;temp<a[i];temp++)
                    sk.push(temp);
                    temp++;
            }
            }
            while(!sk.empty())
            sk.pop();
            if(i < n) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
        cout << endl;
    }
}
