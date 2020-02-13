#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    int max = 0 ;
    int min = 99999999;
    int flag = 0;
    
    bool wordBreak(string s, vector<string>& wordDict) {
    
        unordered_map<string,int> umap;      
        vector<int> save(s.size(), 0);
        
        for(auto it : wordDict) {
            umap[it] = 1;
            
            min = it.size() < min ? it.size() : min;
            max = it.size() > max ? it.size() : max;
        }
        // cout << "s.size() : " << s.size() << endl;
        
        recursive_wordBreak(s,0,umap,save);
        
        return flag;
    };

    void recursive_wordBreak(string s, int index, unordered_map<string,int> &umap, vector<int> &save) {
        
        if(index >= s.size()) {
            flag = 1;
            return;   
        }
        
        if(flag || save[index] == -1)
            return;
        
        // cout << "Index : " << index << endl;

        for(int next = index + min ; next < index + max + 1 ; ++next) {
            //cout << s.substr(index,next-index) << endl;
            if(umap.count(s.substr(index,next-index))) {
                // cout << "Next : "<< next << endl;
                recursive_wordBreak(s, next, umap, save);
                if(flag)
                    return;
            } 
        }
        
        save[index] = -1;
    
        return;
        
    }
    
};

class Solution5 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int a, b, c = 0 ;

        unordered_map<string,int> umap; 
        for(auto it : wordDict)
            umap[it] = 1;

        return recursive_wordBreak(s,0,1,umap);
    }

    bool recursive_wordBreak(string s, int L, int R, unordered_map<string,int> &umap) {
        
        if(L == s.size())
            return true;
        else if (R > s.size())
            return false;
        
        //cout << s.substr(L,R-L) << endl;
      
        if(umap.count(s.substr(L,R-L)))
            if(recursive_wordBreak(s, R, R+1, umap))
               return true;
        
        return recursive_wordBreak(s, L, R+1, umap);

    }
};

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max = 0 ;

        unordered_map<string,int> umap; 
        for(auto it : wordDict) {
            umap[it] = 1;
            
            max = it.size() > max ? it.size() : max;
        }

        return recursive_wordBreak(s,0,1,max,umap);
    }

    bool recursive_wordBreak(string s, int L, int R, int max, unordered_map<string,int> &umap) {
        
        int A = L , B = R;
        
        if(L == s.size())
            return true;
        else if (R > s.size())
            return false;
        else if (R-L > max)
            return false;
        
        //cout << s.substr(L,R-L) << endl;
      
        if(umap.count(s.substr(L,R-L)))
            if(recursive_wordBreak(s, R, R+1, max, umap))
               return true;
        
        
        return recursive_wordBreak(s, L, R+1, max, umap);

    }
};

class Solution3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max = 0 ;
        int min = 99999999;

        unordered_map<string,int> umap; 
        for(auto it : wordDict) {
            umap[it] = 1;
            
            min = it.size() < min ? it.size() : min;
            max = it.size() > max ? it.size() : max;
        }

        return recursive_wordBreak(s,0,1,min,max,umap);
    }

    bool recursive_wordBreak(string s, int L, int R, int min, int max, unordered_map<string,int> &umap) {
        
        int A = L , B = R;
        
        if(L == s.size())
            return true;
        else if (R > s.size())
            return false;
        else if (R-L > max)
            return false;
        
        //cout << s.substr(L,R-L) << endl;
      
        if(umap.count(s.substr(L,R-L)))
            if(recursive_wordBreak(s, R, R+min, min, max, umap))
               return true;
        
        
        return recursive_wordBreak(s, L, R+1, min, max, umap);

    }
};

class Solution4 {
public:
    int max = 0 ;
    int min = 99999999;
    int flag = 0;
    
    bool wordBreak(string s, vector<string>& wordDict) {
    
        unordered_map<string,int> umap;      

        
        for(auto it : wordDict) {
            umap[it] = 1;
            
            min = it.size() < min ? it.size() : min;
            max = it.size() > max ? it.size() : max;
        }
        
        
        
        return recursive_wordBreak(s,0,max,umap);
    }

    bool recursive_wordBreak(string s, int L, int R, unordered_map<string,int> &umap) {
        
        if(flag == 2)
            return true;
        
        if(L == s.size()) {
            flag = 2;
            return true;
        } else if (R > s.size())
            return false;
        else if (R == s.size() && R-L == min){
            if(!umap.count(s.substr(R,R-L)))
                flag = 1;
        }
        
        
        for(int i = R ; i >= L + min; --i) {
            
            //cout << s.substr(L,i-L) << endl;

            if(umap.count(s.substr(L,i-L))) {
                if(recursive_wordBreak(s, i, i+max, umap))
                    return true;
            } 
            if(flag == 1)
                return false;
        }
        
        
            
        return false;
        
    }
    
};

int main()
{
    //vector<int> req( { 4, 5, 6, 1, 0, 1, 2});   
    // string str = "110"; 
    string str = "1123"; 
    // string str = "27"; 
    Solution a;

  
    cout << a.numDecodings(str) << endl;
     

    return 0;
}