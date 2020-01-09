#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        for (int i = 0 ; i < nums.size(); ++i) {
            sum = nums[i];
            if(sum == k)
                count++;
            for (int j = i + 1; j < nums.size(); ++j){
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> abc({
        1,1,1
    });
    Solution a;

    cout << a.subarraySum(abc,2) << endl;

    


    return 0;
}

