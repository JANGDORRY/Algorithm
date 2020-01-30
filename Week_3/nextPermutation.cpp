#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_size = nums.size();
        vector <int> tmp;

        for(int i = 0; i < nums_size; ++i) {
            int curr = nums.back();
            nums.pop_back();
            
            int tmp_size = tmp.size();
            for (int j = 0; j < tmp_size; ++j) { 
                if(tmp[j] <= curr) { 
                    //cout << curr << " : " << tmp[j] << endl;
                    continue;
                }else {
                    //cout << "[Found]"<< curr << " : " << tmp[j] << endl;
                    nums.push_back(tmp[j]);
                    for(int k = 0 ; k < tmp.size() ; ++k) {
                        if(k == j) {
                            nums.push_back(curr);
                        } else {
                            nums.push_back(tmp[k]);
                        }
                    }
                    tmp.clear();
                    return; 
                }
                
            }
            tmp.push_back(curr);
            sort(tmp.begin(), tmp.end());
        }
        for(int j = 0 ; j < tmp.size() ; ++j) {
            nums.push_back(tmp[j]);
        }
        tmp.clear();
        return;
    }
};

// 1 2 3 4 5 6
// 1 2 3 4 6 5
// 1 2 3 5 4 6
// 1 2 3 5 6 4
// 1 2 3 6 4 5 

// 6 5 4 3 2 1

int main()
{
    vector<int> req( { 1, 3, 2 });   
    Solution a;

    for (int i = 0 ; i < req.size(); ++i ) {
        cout << req[i] << " , ";
    }
    cout << endl;
   

    a.nextPermutation(req);
    for (int i = 0 ; i < req.size(); ++i ) {
        cout << req[i] << " , ";
    }
    cout << endl;


    // cout << endl;
    // a.nextPermutation(req);
    // for (int i = 0 ; i < req.size(); ++i ) {
    //     cout << req[i] << " , ";
    // }
    // cout << endl;

    // a.nextPermutation(req);
    // for (int i = 0 ; i < req.size(); ++i ) {
    //     cout << req[i] << " , ";
    // }
    // cout << endl;
    

    // a.nextPermutation(req);
    // for (int i = 0 ; i < req.size(); ++i ) {
    //     cout << req[i] << " , ";
    // }
    // cout << endl;

    // a.nextPermutation(req);
    // for (int i = 0 ; i < req.size(); ++i ) {
    //     cout << req[i] << " , ";
    // }
    // cout << endl;

    // a.nextPermutation(req);
    // for (int i = 0 ; i < req.size(); ++i ) {
    //     cout << req[i] << " , ";
    // }
    // cout << endl;
    return 0;
}