#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        multiset<long long int> bags;
        for(int i=0; i<n; i++){
            long long int candy_ct;
            cin >> candy_ct;
            bags.insert(candy_ct);
        }

        long long int total_candies = 0;
        for(int i=0; i < k; i++){
            auto it = (--bags.end());
            long long int candy_ct = (*it);
            // cout << "candy_ct: " << candy_ct << endl;
            total_candies += candy_ct;
            bags.erase(it);
            bags.insert(candy_ct / 2);
        }

        cout << total_candies << endl;
    }
}