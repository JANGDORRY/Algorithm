class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        vector<vector<string>> ans;
        vector<vector<string>> tmp;
        unordered_map<string, int> m;
        int count = 0;
        
        int paths_len = paths.size();
        for (int i = 0 ; i < paths_len ; ++i) {
            //cout <<endl << paths[i] << endl;
            int string_len = paths[i].size();
            int path_len = 0;
            
            string path;
            string content;
            string filename_with_path;
            
            int filename_start = 0 , filename_end = 0;
            for (int j = 0; j < string_len ; ++j) {
                
                if (paths[i][j] == ' ') {
                    if (!path_len) {
                        path_len = j;
                        path= paths[i].substr(0, j);
                        path.push_back('/');
                        //cout << path << endl;
                    }
                       
                    filename_start = j + 1;
                    
                } else if (paths[i][j] == '(') {
                    filename_end = j - 1;
                    filename_with_path = path + paths[i].substr(filename_start, filename_end - filename_start + 1);
                    
                    //cout << filename_with_path << endl;
                    
                } else if (paths[i][j] == ')') {
                    
                    content = paths[i].substr(filename_end + 2, j - filename_end - 2);
                    if(!m.count(content)) {
                        m[content] = count++;
                        tmp.push_back(vector<string>(0));
                    } 
                    
                    tmp[m[content]].push_back(filename_with_path);
                    filename_with_path.clear();
                    
                }
                // if (path)
                //     cout << "found " << i << " "<< j<< endl;
            }
        }
        
        int tmp_size = tmp.size();
        for(int i = 0; i < tmp_size ; ++i) {
            if(tmp[i].size() > 1) {
                ans.push_back(tmp[i]);
            }
        }
        
        
        return ans;
    }
};