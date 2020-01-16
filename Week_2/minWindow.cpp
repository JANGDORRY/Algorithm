#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>


class Solution {
public:
    string minWindow(string s, string t) {

        int s_l = s.length(), t_l = t.length();
        cout << "length " << s_l << ", " << t_l << endl;
        unordered_map<char, int> m_t;
        string a, b; 
        int k = 0; 
        for (int i = 0 ; i < t_l; ++i) {
            if(m_t.count(t.at(i))) {
                b[m_t.find(t.at(i))->second]++;
            } else {
                a.push_back('0');
                b.push_back('1');
                m_t.insert(make_pair(t.at(i), k));
                k++;
            }
        }

        vector<pair<string, int>> p_v;
        unordered_map<string, int> n_m;
        //cout << s.at(2) << endl;
        for (int i = 0 ; i < s_l; ++i) {

            if(m_t.count(s.at(i))) {
                p_v.push_back(make_pair(b,i));
                a.at(m_t.find(s.at(i))->second)++;
                b.at(m_t.find(s.at(i))->second)++;
                n_m.insert(make_pair(a,i));
            }
            cout << "insert " << i<< " : "<< b << ", " << a << endl;
        }

        tuple<int,int,int> min1 = make_tuple(999999,0,0);
        pair<int,int> min = make_pair(999999,-1);
        for (auto it : p_v) {
            string s_1 = it.first;
            if(n_m.count(s_1)) {
                int n_1 = it.second;
                int n_2 = n_m.find(it.first)->second;
                if (min.first > n_2 - n_1 +1){
                    min = make_pair( n_2 - n_1 +1, n_1);
                    
                    cout <<"Hello"<< n_1<< "," << n_2 << endl;
                }
            }
        }

            
        return min.second == - 1 ? "" : s.substr(min.second,min.first);
    }
};

int main()
{
    
    Solution a;

    cout << a.minWindow("aaaaaaaaaaaabbbbbcdd","abcdd") << endl;

    


    return 0;
}