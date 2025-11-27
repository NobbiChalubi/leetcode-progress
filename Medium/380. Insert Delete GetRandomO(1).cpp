#include <iostream>
#include <unordered_map>    
#include <vector>
#include <random>

//Problem: Insert Delete GetRandomO(1)
//Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/
//Date: 11/24/25
//Difficulty: Medium
//Time Complexity: O(1)
//Space Complexity: O(n)
//Concepts: Hash Table, Vector, Random
//Notes: 

class RandomizedSet {
public:
    int newValue = 0;
    int index = 0;
    std::unordered_map<int,int> map;
    std::vector<int> vec;
    std::mt19937 gen;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end()){return false;}
        else{
            map.insert({val,index});
            vec.push_back(val);
            index+=1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(map.find(val)!=map.end()){
            newValue = vec[vec.size()-1];
            map[newValue] = map.at(val);
            vec[map.at(val)] = newValue;
            vec.pop_back();
            map.erase(val);
            index-=1;
            return true;
        }
        else{return false;}
        
    }
    
    int getRandom() {
        if(vec.size()!=0){
            std::uniform_int_distribution<int> ranNumFromRanges(0, vec.size()-1);
            return vec[ranNumFromRanges(gen)];
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){

    RandomizedSet randomizedSet;

    std::cout<<randomizedSet.getRandom()<<"\n";

    std::cout<<randomizedSet.insert(-1)<<"\n";
    std::cout<<randomizedSet.remove(-2)<<"\n";
    std::cout<<randomizedSet.insert(-2)<<"\n";
    std::cout<<randomizedSet.getRandom()<<"\n";
    std::cout<<randomizedSet.remove(-1)<<"\n";
    std::cout<<randomizedSet.insert(-2)<<"\n";
    std::cout<<randomizedSet.getRandom()<<"\n";

    return 0;
}