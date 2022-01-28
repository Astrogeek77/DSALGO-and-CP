#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int q;
    cin >> q;
    while(q--){
        int y, x;
        cin >> y >> x;
        switch(y){
        case 1:
            s.insert(x);
            break;
        case 2:
            s.erase(y);
            break;
        case 3:
            cout << (s.find(y) != s.end() ? "Yes" : "No") << endl;
            break;
        }
    }
    return 0;
}
