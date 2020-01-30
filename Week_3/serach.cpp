#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nums_size = nums.size();   
        if(nums_size == 0) return -1;
        int a = 0, b = nums_size / 2 , c = nums_size; 
        int pv = 0;
        
        while(1) {
            //cout << "[1] [" << a << " , " << b << " , " << c << " ] " << endl;
            
            if(nums[a] < nums[b]) {
                //cout << " UP " << endl;
                a = b;
                b = (c + a) / 2;
                
            } else if (nums[a] > nums[b]){
                //cout << " Down " << endl;
                c = b;
                b = (c + a) / 2;
                
            }

            if(a == b) {
                break;
            } 

        }
        pv = a + 1;
        //cout << "pv : " << pv << endl;
        a = 0;
        c = nums_size;
        b = nums_size / 2;
        
        while(1) {
            int curr = (b + pv) % nums_size;
            //cout << "[2] [" << a << " , " << b << " , " << c << " ] " << endl;
            
            if(nums[curr] == target){
                return curr;
                break;
            } else if(nums[curr] < target) {
                //cout << " UP " << endl;
                a = b;
                b = (c + a) / 2;
            } else if (nums[curr] > target){
                //cout << " Down " << endl;
                c = b;
                b = (c + a) / 2;
            }

            if(a == b)
                break;

        }

        if (nums[(b + pv) % nums_size] == target)
            return (b + pv) % nums_size;
        else   
            return -1;

    }
};

int main()
{
    //vector<int> req( { 4, 5, 6, 7, 0, 1, 2});   
    vector<int> req( { 1,3});   
    Solution a;

    for (int i = 0 ; i < req.size(); ++i ) {
        cout << req[i] << " , ";
    }
    cout << endl;
    
    cout << a.search(req , 3) << endl;
   

    

    return 0;
}