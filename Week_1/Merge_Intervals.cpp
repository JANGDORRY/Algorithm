#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include<algorithm>



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > sol;
        vector<int> tmp(2);
        int first = 0, last = 0 , flag = 0; 

        for (vector<int> vec : intervals) {

            if (flag == 0) {
                first = vec[0];
                last = vec[1]; 
                flag = 1;
            } else {
                if ( vec[0] <= last ) {
                    last = last < vec[1] ? vec[1] : last;
                } else {
                    tmp[0] = first;
                    tmp[1] = last;
                    sol.push_back(tmp);
                    first = vec[0];
                    last = vec[1];
        
                }
            }    
        }
        if (flag == 1) {
            tmp[0] = first;
            tmp[1] = last;
            sol.push_back(tmp);
        }
        return sol;
        
    }
};

int main()
{
    vector<vector<int> > sol;
    
    vector<vector<int> > intervals({
        vector<int>({1,3}),
        vector<int>({0,2}),
        vector<int>({2,6}),
        vector<int>({8,10}),
        vector<int>({15,18})
    });

    Solution a;
    sol = a.merge(intervals);
    for(vector<int> vt : sol)
        cout << vt[0] <<","<<vt[1]<<","<<vt[2]<<endl;



    return 0;
}

