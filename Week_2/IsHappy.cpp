#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>


class Solution {
public:
    bool isHappy(int n) {

        unordered_map<int,int> m;
        m.insert(make_pair(n,1));
        string A;
        int B = n;

        while(1) {
            A = to_string(B);
            B = 0;

            for (int i = 0 ; i < A.size() ; ++i) {
                B += (A.at(i) - 48)*(A.at(i) - 48) ;
            }
            if(B == 1)
                return true;
            else if (m.count(B))
                return false;
            
            //cout << B << endl;
            m.insert(make_pair(B,1));
        }
        
    }
};

int main()
{
    
    Solution a;

    cout << a.isHappy(19) << endl;

    


    return 0;
}