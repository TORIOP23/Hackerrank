/*
    -
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s = "";
    stack<string> str;
    str.push(s);
    int q;
    cin >> q;
    while (q > 0) {
        int op;
        cin >> op;
        if (op == 1) {
            string w;
            cin >> w;
            s = s + w;
            str.push(s);
        } else if (op == 2) {
            int k;
            cin >> k;
            s.erase(s.size() - k, k);
            str.push(s);
        } else if (op == 3) {
            int k;
            cin >> k;
            cout << s[k - 1] << endl;
        } else {
            str.pop();
            s = str.top();
        }
        q--;
    }
    return 0;
}

