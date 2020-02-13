#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
       
        vector<int> save;
        
        // for(auto it : nums) {
        //     q.push(it);
        // } 
        //
        recursive_subsets(nums, save ,0, nums.size(), ans);
        
        return ans;
    }
    
    void recursive_subsets(vector<int> &nums, vector<int> &save, int n, int N,  vector<vector<int>> &ans) {
        
        if(n == N) {      
            ans.push_back(save);
            return;
        }

        //cout<< nums[n] << endl;
        // O
        save.push_back(nums[n]);
        recursive_subsets(nums, save, n+1, N, ans);
        // X 
        save.erase(save.end()-1);
        recursive_subsets(nums, save, n+1, N, ans);
       
        
        
    }
};

int main()
{
    //vector<int> req( { 4, 5, 6, 7, 0, 1, 2});   
    vector<int> req( { 1,2,3,4} ); 
    // 1 / 2 / 3/ 4/ 1 2 / 1 3 / 1 4 / 2 3 / 2 4/ 3 4/ 1 2 3 / 1 2 4/ 1 3 4 / 2 3 4/ 1 2 3 4   
    Solution a;
    vector<vector<int>> ans; 
    ans = a.subsets(req);
    
    
    for (int i = 0 ; i < ans.size(); ++i ) {
        for (int j = 0 ; j < ans[i].size(); ++j )
            cout << ans[i][j] << " , ";

        cout << endl;
    }
    cout << endl;
    

    

    return 0;
}