#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        queue<int> q;
        vector<int> save;
        int nums_size = nums.size();
        
        for(auto it : nums) {
            q.push(it);
        } 
        //cout<< "hello" << endl;
        recursive_permute(save, q, ans);
        
        return ans;
    }
    
    void recursive_permute(vector<int> &save, queue<int>& q, vector<vector<int>> &ans) {
        //cout << "hello 2 " << endl;
        if(!q.size()) {
            // vector<int> tmp = save;
            ans.push_back(save);
            //cout << "Return" << endl;
            return;
        } else {
            int q_size = q.size();
            //printf("q_size %d \n", q_size);
            for(int i = 0; i < q_size ; ++i) {
                int num = q.front();
                q.pop();
                save.push_back(num);
                recursive_permute(save,q,ans);
                save.erase(save.end()-1);
                q.push(num);
            }
            
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int numsLen = nums.size();
        vector<int> orig = nums;
        vector<vector<int>> result;
        do
        {
            result.push_back( nums );
            next_permutation( nums.begin(), nums.end() );
            
        }while(orig != nums );
            
            return result;
    }
};

int main()
{
    //vector<int> req( { 4, 5, 6, 7, 0, 1, 2});   
    vector<int> req( { 1,2,3});   
    Solution a;
    vector<vector<int>> ans; 
    ans = a.permute(req);
    
    
    for (int i = 0 ; i < ans.size(); ++i ) {
        for (int j = 0 ; j < ans[i].size(); ++j )
            cout << ans[i][j] << " , ";

        cout << endl;
    }
    cout << endl;
    

    

    return 0;
}