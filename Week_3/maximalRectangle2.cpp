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
        int x_len = matrix.size();
        if (!x_len) return 0;
        int y_len = matrix[0].size();
        
        int max = 0;

        vector<vector<vector<int>>> tmp(x_len, vector<vector<int>>(y_len, vector<int>(3)));

        for (int i = 0 ; i < x_len; ++i ) {
            for (int j = 0 ; j < y_len ; ++j ) {
                if(matrix[i][j] == '1') {
                    int x_max = 1 , y_max = 1;

                    if(tmp[i][j][1] == 0 ) tmp[i][j][1]++;
                    if(tmp[i][j][0] == 0 ) tmp[i][j][0]++;

                    if(i + 1 < x_len && matrix[i+1][j] == '1')
                        tmp[i+1][j][1] += tmp[i][j][1] + 1;

                    if(j + 1 < y_len && matrix[i][j+1] == '1')
                        tmp[i][j+1][0] += tmp[i][j][0] + 1;



                    int d_x = tmp[i][j][0] - 1;
                    int d_y = tmp[i][j][1] - 1;
                    int t_max = 0;
                    cout << "["<< d_x << " , " << d_y << "]," ;
                    
                    for (int x = 1 ; x <= d_x; ++x) {
//                         if(tmp[i][j-x][1] < d_y)
//                             break;;
                        
                        for (int y = 1 ; y <= d_y ; ++y) {
                            if(tmp[i-y][j][0] - 1 < x)
                                break;
                            
                            int k = (x + 1) * (y + 1);
                            if(t_max < k) t_max = k;
                            cout << " "<< x<<"*"<<y;
                            
                        }
                    }
                    
                    // int t_max = 0;
                    // for (int t_y = 1 ; t_y < tmp[i][j][1] ; ++t_y) {
                    //     int t_x = tmp[i- t_y][j][0];
                    //     if(t_x >= 1 && t_x <= tmp[i][j][0] ) {
                    //        if(tmp[i][j- t_x + 1][1] >= (t_y+1)){
                    //            t_max = t_max > (t_x) * (t_y+1) ? t_max :  (t_x)  * (t_y+1);
                    //        }
                    //     } 
                    // }

                    // for (int t_x = 1 ; t_x < tmp[i][j][0] ; ++t_x) {
                    //     if(tmp[i][j - t_x][1] >= x_max) {
                    //         y_max++;
                    //     } else {
                    //         break;
                    //     }
                    // }

                    
                    

                    //tmp[i][j][2] = x_max * y_max;
                    tmp[i][j][2] = tmp[i][j][0] > tmp[i][j][1] ? tmp[i][j][0] : tmp[i][j][1]; 
                    //tmp[i][j][2] = tmp[i][j][2] > x_max * y_max ? tmp[i][j][2] :  x_max * y_max;
                    tmp[i][j][2] = tmp[i][j][2] > t_max ? tmp[i][j][2] :  t_max;
                    
                    max = max > tmp[i][j][2] ? max : tmp[i][j][2];


                } else
                    cout << "["<< -1 << " , " << -1 << "] ," ;
            }
            cout << endl;
        }

        for (int i = 0 ; i < x_len ; ++i ) {
            for (int j = 0 ; j < y_len ; ++j) 
                cout << "["<< tmp[i][j][0] << " , " <<  tmp[i][j][1]<<" , "<< tmp[i][j][2] << "] ," ;

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