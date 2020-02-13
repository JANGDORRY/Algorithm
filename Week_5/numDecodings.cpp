#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

class Solution {
public:
    int numDecodings(string s) {
        vector<int> save(s.size(),-1);
        return recur_numDecodings(s,s.size()-1, save);
    }

    int recur_numDecodings(string s, int b_index, vector<int> &save){

        if(b_index == -1)
            return 1;

        if(save[b_index] != -1)
            return save[b_index];

        int sum = 0;

        if (b_index > 0 && s[b_index-1] != '0' && (int(s[b_index]-48) + 10 * int(s[b_index-1]-48)) <= 26)
            sum = sum + recur_numDecodings(s,b_index-2, save);
    
        if(s[b_index] != '0') {
            sum = sum + recur_numDecodings(s,b_index-1, save);
        }
        
        save[b_index] = sum;
        return sum;
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
     
        return recur_numDecodings(s,s.size()-1);
    }

    int recur_numDecodings(string s, int b_index){

        if(b_index == -1)
            return 1;

        int sum = 0;

        if (b_index > 0 && s[b_index-1] != '0' && (int(s[b_index]-48) + 10 * int(s[b_index-1]-48)) <= 26)
            sum = sum + recur_numDecodings(s,b_index-2);
    
        if(s[b_index] != '0') {
            sum = sum + recur_numDecodings(s,b_index-1);
        }
        
        return sum;
    }
};


int main()
{
    //vector<int> req( { 4, 5, 6, 1, 0, 1, 2});   
    // string str = "1111"; 
    string str = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"; 
    // string str = "27"; 
    Solution a;

  
    cout << a.numDecodings(str) << endl;
     

    return 0;
}