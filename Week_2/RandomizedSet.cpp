#include <iostream>



using namespace std;

#include <algorithm>
#include <vector>
#include <unordered_map>
// #include <string>

class RandomizedSet {

public:
    unordered_map<int, int> m ;
    int count = 0;
    /** Initialize your data structure here. */
    RandomizedSet() {
        //srand(5323); 
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val))
            return false;
        else
        {
            m.insert(make_pair(val,1));
            return true;
        }
        
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.count(val)) {
            m.erase(val);
            return true;
        }  else {
            return false;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (!m.size()) return 0;
        
        int a = rand() % m.size();
        int i = 0;
        for(auto b : m) {
            if (i++ == a)
                return b.first;
            
        }
        return 0;
    }
        
//         //cout << "hello  "<< m.begin(a)->first<< endl;
//         if (it != m.end())
//             return it->first;
        //return 2;
        
    
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    
    // Init an empty set.
    RandomizedSet *randomSet = new RandomizedSet();

    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << randomSet->insert(1) << endl;

    // Returns false as 2 does not exist in the set.
    cout << randomSet->remove(2) << endl;
    
    // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << randomSet->insert(2) << endl;
  

    // getRandom should return either 1 or 2 randomly.
    cout << randomSet->getRandom() << endl;
    

    // Removes 1 from the set, returns true. Set now contains [2].
    cout << randomSet->remove(1) << endl;
    //randomSet->remove(1);

    // 2 was already in the set, so return false.
    cout << randomSet->insert(2) << endl;
    

    // Since 2 is the only number in the set, getRandom always return 2.
    cout << randomSet->getRandom()<< endl;
    


    return 0;
}