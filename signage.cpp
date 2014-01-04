#include <iostream>
#include <string>
#define SET(x) for (int i = 0; i < sizeof((x))/sizeof(int);i++){(x)[i]=0;}
using namespace std;

string words[] = {"WELCOME","TO","CCC","GOOD","LUCK","TODAY"};
int length[] = {7,2,3,4,4,5};
#define SIZE 6
int main()
{
    string out;
    int limit;
    cin >> limit;
    int cnt=0;
    int a = 0;
    while (cnt < SIZE)
    {
        int sum = 0;
        int n = 0;
        out = "";
        while (sum < limit+1)
        {
            //cout << "cnt " << cnt << endl;
            if (cnt > SIZE) {
                    //cout << cnt << " broken" << endl;
                break;
            }
            sum+=length[cnt]+1;
            //cout << "sum " << sum << endl;
            if (sum > limit+1)
                break;
            n+=1;

            cnt += 1;
        }
        //cout << n << endl;
        int gap[n-1];
        for (int i = 0; i < n-1; i++) {
            gap[i]=1;
        }
        int c = 0;
        sum = 0;
        for (int i = cnt - n; i < n; i++) {
            sum += length[i] + 1;
        }
        sum --;
        //cout << "sum" << sum << endl;
        while (sum<limit)
        {
            gap[c++%n]++;
            sum++;
        }
        //cout << "building" << endl;
        for (int i = cnt-n,a=0; a<n&&i<SIZE; i++,a++)
        {
            //cout << i << " ";
            //cout << words[i] << endl;
            out += words[i];
            if (a<n-1) {
                    //cout << gap[a] << " j ";
                for (int j = 0; j < gap[a]; j++) {
                    out+=".";
                  //  cout << j << " ";
                }
                //cout << endl;
            }
        }
        cout << out << endl;
    }
}
