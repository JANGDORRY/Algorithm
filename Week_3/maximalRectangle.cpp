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



                    int t_max = 0;
                    for (int t_y = 1 ; t_y < tmp[i][j][1] ; ++t_y) {
                        int t_x = tmp[i- t_y][j][0];
                        if(t_x >= 1 && t_x <= tmp[i][j][0] ) {
                           if(tmp[i][j- t_x + 1][1] >= (t_y+1)){
                               t_max = t_max > (t_x) * (t_y+1) ? t_max :  (t_x)  * (t_y+1);
                           }
                        } 
                    }

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


                }
            }
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