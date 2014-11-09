#include <iostream>
/*
Problem Description
You know a family with three children. Their ages form an arithmetic sequence: the difference in
ages between the middle child and youngest child is the same as the difference in ages between
the oldest child and the middle child. For example, their ages could be 5, 10 and 15, since both
adjacent pairs have a difference of 5 years.
Given the ages of the youngest and middle children, what is the age of the oldest child?
Input Speciﬁcation
The input consists of two integers, each on a separate line. The ﬁrst line is the age Y of the
youngest child (0  Y  50). The second line is the age M of the middle child (Y  M  50)
*/

using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    cout << b+(b-a) << endl;
}
