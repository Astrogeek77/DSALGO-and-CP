#include <bits/stdc++.h>
using namespace std;


int main(){
    // vector<int> v = {2, 3, 4, 5, 6};

    // vector<int>::iterator it;

    // v.push_back(7); // o(1)

    // for(it = v.begin(); it != v.end(); it++){
    //     cout << (*it) << endl;
    // }

    // vector<pair<int, int>> v_p = {{2, 3}, {4, 5}, {6, 7}};
    // vector<pair<int, int>>::iterator it_p;

    // for(it_p = v_p.begin(); it_p < v_p.end(); it_p++){
    //     cout << it_p->first << " " << it_p->second << endl;
    // }

    // for(it_p = v_p.begin(); it_p < v_p.end(); it_p++){
    //     cout << (*it_p).first << " " << (*it_p).second << endl;
    // }

    // for(pair<int, int> value : v_p){
    //     cout << value.first << " " << value.second << endl;
    // }
    // for(pair<int, int> &value : v_p){
    //     cout << value.first << " " << value.second << endl;
    // }
    // for(auto &value : v_p){
    //     cout << value.first << " " << value.second << endl;
    // }

    // auto a = 1;
    // cout << typeid(a).name << " "

    // map<int, string> m;  // uses Red Black Trees
    // m[5] = "Banana"; // O(log(n))
    // m[1] = "Apple";
    // m.insert({4, "Peach"});
    // m[2] = "Orange";
    // m[3] = "Banana";
    // m[6]; //  O(log(n))

    // cout << "Size: " << m.size() << endl;

    // cout << m[4] << endl;

    // for(auto &value : m){   // O(nlog(n))
    //     cout << value.first << " " << value.second << endl;
    // }

    // auto it = m.find(6); // returns iterator if found else m.end() o(log(n))
    // it == m.end() ? cout << "Not Found" << endl : cout << "Found" << endl;


    // if(it != m.end())
    //     m.erase(it);  // o(log(n))

    // cout << "Size: " << m.size() << endl;

    // for(auto &value : m){   // O(nlog(n))
    //     cout << value.first << " " << value.second << endl;
    // }


    // unordered_map<int, string> m;  // uses Hashtables
    // m[5] = "Banana"; // O(1)
    // m[1] = "Apple";
    // m.insert({4, "Peach"});
    // m[2] = "Orange";
    // m[3] = "Banana";
    // m[6]; //  O(1)

    // cout << "Size: " << m.size() << endl;

    // cout << m[4] << endl;

    // for(auto &value : m){   // O(n)
    //     cout << value.first << " " << value.second << endl;
    // }

    // auto it = m.find(6); // returns iterator if found else m.end() o(log(n))
    // it == m.end() ? cout << "Not Found" << endl : cout << "Found" << endl;


    // if(it != m.end())
    //     m.erase(it);  // o(l)

    // cout << "Size: " << m.size() << endl;

    // for(auto &value : m){   // O(n)
    //     cout << value.first << " " << value.second << endl;
    // }

    // map<int, int> m;
    // m.insert(pair<int, int>(1, 2));
    // m.insert({2, 4});
    // m[3] = 6;

    // for(auto &value : m) cout << value.first << " " << value.second << endl;

    // cout << m.max_size() << endl;

    // maps can handle every datatype
    // unordered_maps can only handle primitive datatypes because of requirement of hashing functions.

    // sets are like maps, and unordered_sets are like unordered_maps

    // set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(1);

    // for(auto &value : s)
    //     cout << value << endl;

    // auto it = s.find(3);
    // if(it != s.end()) s.erase(it);

    // for(auto &value : s)
    //     cout << value << endl;


    multiset<pair<int, int> >m_s; // just like maps and sets but can store non-unique values
    m_s.insert(make_pair(1, 2));
    m_s.insert({2, 4});
    m_s.insert({2, 4});
    m_s.insert(pair<int, int>(3, 6));

    cout << m_s.size() << endl;
    for(auto &value : m_s) cout << value.first << " " << value.second << endl;

    auto it = m_s.find({2, 4});

    // if(it != m_s.end()) m_s.erase(it); // removes the first occurence only.

    m_s.erase({2, 4}); // removes all the occurences.
    cout << "================================================================" << endl;
    cout << m_s.size() << endl;
    for(auto &value : m_s) cout << value.first << " " << value.second << endl;
 }