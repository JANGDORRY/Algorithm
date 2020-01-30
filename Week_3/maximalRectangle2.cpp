#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int y_len = matrix.size();
        if (!y_len) return 0;
        int x_len = matrix[0].size();
        
        int max = 0;
        

        vector<vector<vector<int>>> tmp(y_len, vector<vector<int>>(x_len, vector<int>(3)));

        for (int y = 0 ; y < y_len; ++y ) {
            for (int x = 0 ; x < x_len ; ++x ) {
                if(matrix[y][x] == '1') {
                    int x_max = 1 , y_max = 1;

                    if(tmp[y][x][1] == 0 ) tmp[y][x][1]++;
                    if(tmp[y][x][0] == 0 ) tmp[y][x][0]++;

                    if(y + 1 < y_len && matrix[y+1][x] == '1')
                        tmp[y+1][x][1] += tmp[y][x][1] + 1;

                    if(x + 1 < x_len && matrix[y][x+1] == '1')
                        tmp[y][x+1][0] += tmp[y][x][0] + 1;

                    // cout << "hello2 " << endl;

                    int t_max = 0;
                    // for (int d_y = 1 ; d_y < tmp[y][x][1] ; ++d_y) {
                    //     int d_x = tmp[y- d_y][x][0] - 1;
                    //     if(d_x >= 1 && d_x <= tmp[y][x][0] ) {
                    //        if(tmp[y][x- d_x][1] >= (d_y+1)){
                    //            t_max = t_max > (d_x + 1) * (d_y+1) ? t_max :  (d_x + 1)*(d_y+1);
                    //            cout <<"[" << x << " , " << y <<"]"<< d_x + 1 << " : "<< d_y + 1 << endl;
                    //        }
                    //     } 
                    // }

                    // for (int t_x = 1 ; t_x < tmp[y][x][0] ; ++t_x) {
                    //     if(tmp[y][x - t_x][1] >= x_max) {
                    //         y_max++;
                    //     } else {
                    //         break;
                    //     }
                    // }
                    // cout << y << x  << endl;
                    
                    

                    //tmp[y][x][2] = x_max * y_max;
                    tmp[y][x][2] = tmp[y][x][0] > tmp[y][x][1] ? tmp[y][x][0] : tmp[y][x][1]; 
                    //tmp[y][x][2] = tmp[y][x][2] > x_max * y_max ? tmp[y][x][2] :  x_max * y_max;
                    tmp[y][x][2] = tmp[y][x][2] > t_max ? tmp[y][x][2] :  t_max;
                    
                    max = max > tmp[y][x][2] ? max : tmp[y][x][2];


                }
            }
        }

        for (int y = 0 ; y < y_len ; ++y ) {
            for (int x = 0 ; x < x_len ; ++x) 
                cout << "["<< tmp[y][x][0] << " , " <<  tmp[y][x][1]<<" , "<< tmp[y][x][2] << "] ," ;

            cout << endl;
        }

        
        cout << endl;
        return max;
    }
};

int main()
{
    // vector< vector<char> > req({
    //                             vector<char>({'1','0','1','0','0'}),
    //                             vector<char>({'1','0','1','1','1'}),
    //                             vector<char>({'1','1','1','1','1'}),
    //                             vector<char>({'1','0','0','1','0'})
    //                             });
    vector< vector<char> > req({
                                vector<char>({'0','1','0','0','1'}),
                                vector<char>({'1','1','1','1','0'}),
                                vector<char>({'0','1','1','1','0'}),
                                vector<char>({'1','1','1','1','0'}),
                                vector<char>({'1','1','1','1','1'}),
                                vector<char>({'0','0','0','0','0'})
                                });     
    //vector<int> req( { 0,1,0,2,1,0,1,3,2,1,2,1});   
    Solution a;

    


    for (int y = 0 ; y < req.size(); ++y ) {
        for (int x = 0 ; x < req[y].size() ; ++x) 
            cout << req[y][x] << " , ";

        cout << endl;
    }
    cout << endl;
    
    cout << a.maximalRectangle(req) << endl;
   
    cout << "hello" << endl;
    

    return 0;
}