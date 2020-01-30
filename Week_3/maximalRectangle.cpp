static const auto _ = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int x_len = matrix.size();
        if (!x_len) return 0;
        int y_len = matrix[0].size();
        
        int max = 0;

        vector<vector<vector<int>>> tmp(x_len, vector<vector<int>>(y_len, vector<int>(2)));

        for (int i = 0 ; i < x_len; ++i ) {
            for (int j = 0 ; j < y_len ; ++j ) {
                if(matrix[i][j] == '1') {
                    int x_max = 1 , y_max = 1;

                    if(tmp[i][j][1] == 0 ) tmp[i][j][1] = 1;
                    if(tmp[i][j][0] == 0 ) tmp[i][j][0] = 1;

                    if(i + 1 < x_len && matrix[i+1][j] == '1')
                        tmp[i+1][j][1] += tmp[i][j][1] + 1;

                    if(j + 1 < y_len && matrix[i][j+1] == '1')
                        tmp[i][j+1][0] += tmp[i][j][0] + 1;



                    int d_x = tmp[i][j][0] - 1;
                    int d_y = tmp[i][j][1] - 1;
                    
                    int t_max = d_x + 1;
                    //if(max < d_x + 1) max = d_x + 1;
                    if(t_max < d_y + 1) t_max = d_y + 1;
                    
                    //int t_max = d_x > d_y ? d_x + 1 : d_y + 1;
                    
                    for (int x = 1 ; x <= d_x; ++x) {
                        for (int y = 1 ; y <= d_y ; ++y) {
                            if(tmp[i-y][j][0] - 1 < x)
                                break;
                            
                            int k = (x + 1) * (y + 1);
                            if(t_max < k) t_max = k;
                        }
                    }
                    
                    if(max < t_max) max = t_max;
                        
                    
                }
            }
        }

        return max;
    }
};