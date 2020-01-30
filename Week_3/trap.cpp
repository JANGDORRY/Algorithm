#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    int trap(vector<int>& height) {
        int h_size = height.size();
        if (!h_size) return 0;

        int a = 0 , b = h_size - 1 , j = 0; 
        int num_a = 0, num_b = 0 , num_i = 0 , num_j = 0;
        int sum = 0 , t_sum1 = 0 , t_sum2 = 0;

        for (int i = 0 ; i < h_size ; ++i ) {
            
            j = h_size - 1 - i;
            num_i = height[i];
            num_j = height[j];

            if ( num_a > num_i ) {
                t_sum1 += num_a - num_i;
            } else if ( num_a <= num_i) {
                a = i ;
                num_a = height[a]; 
                sum += t_sum1;                
                t_sum1 = 0;
            }

            if ( num_b > num_j ) {
                t_sum2 += num_b - num_j;
            } else if ( num_b < num_j) {
                b = j;
                num_b = height[b];
                sum += t_sum2;
                t_sum2 = 0;
            }

        }
    
        return sum; 
    }
};

class Solution3 {
public:
    int trap(vector<int>& height) {
        int h_size = height.size();
        if (!h_size) return 0;

        int a = 0 , b = h_size - 1; 
        int sum = 0 , t_sum1 = 0 , t_sum2 = 0;

        for (int i = 0 ; i < h_size ; ++i ) {
            if ( height[a] > height[i] ) {
                t_sum1 += height[a] - height[i];
            } else if ( height[a] <= height[i]) {
                a = i ;
                sum += t_sum1;
                t_sum1 = 0;
            }

            if ( height[b] > height[h_size - i - 1] ) {
                t_sum2 += height[b] - height[h_size - i - 1];
            } else if ( height[b] < height[h_size - i - 1]) {
                b = h_size - i - 1 ;
                sum += t_sum2;
                t_sum2 = 0;
            }

        }
    
        return sum; 
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int h_size = height.size();
        if (!h_size) return 0;

        int a = 0 , b = 0; 
        int sum = 0 , t_sum = 0;

        for (int i = 0 ; i < h_size ; ++i ) {
            if ( height[a] > height[i] ) {
                //cout << "[ tsum ] [ " << a << " , " << i<<" ] " << endl;
                t_sum += height[a] - height[i];

            } else if ( height[a] <= height[i]) {
                a = i ;
                sum += t_sum;
                t_sum = 0;
                //cout << " sum " << sum << endl;
            }
        }
        //cout << "@@@@@@@@@"<< endl ;
        t_sum = 0 ;
        a = h_size - 1;
        for (int i = h_size - 1 ; i >= 0 ; --i ) {
            if ( height[a] > height[i] ) {
                //cout << "[ tsum ] [ " << a << " , " << i<<" ] " << endl;
                t_sum += height[a] - height[i];

            } else if ( height[a] < height[i]) {
                a = i ;
                sum += t_sum;
                t_sum = 0;
                //cout << " sum " << sum << endl;
            }
        }
        
        return sum; 
    }
};

int main()
{
    vector<int> req( { 4, 2 ,3});   
    //vector<int> req( { 0,1,0,2,1,0,1,3,2,1,2,1});   
    Solution a;

    for (int i = 0 ; i < req.size(); ++i ) {
        cout << req[i] << " , ";
    }
    cout << endl;
    
    cout << a.trap(req) << endl;
   

    

    return 0;
}