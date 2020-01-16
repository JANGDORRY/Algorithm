#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int s_size = s.size();
        if (!s_size) return 0;
        unordered_map<char,int> m;
        
        int a;
        int max = 1;
        int count = 0; 
        for (int i = 0; i < s_size ; ++i ) {
            
            a = s.at(i);
            //cout << a << ", " << i << endl;
            if(!m.count(a)) {
                count++;
                m.insert(make_pair(a,i));
            } else {
                if(max < count ) {
                    max = count;   
                }
                i = m.find(a)->second;
                m.clear();
                count = 0;
            }
        }
        if(max < count ) 
            max = count;
        return max;
    }
};

int main()
{
    
    Solution a;

    cout << a.lengthOfLongestSubstring("dvdf") << endl;

    


    return 0;
}