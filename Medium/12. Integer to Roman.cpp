#include <iostream>
#include <map>
#include <vector>
#include <cmath>

//Problem: Integer to Roman
//Link: https://leetcode.com/problems/integer-to-roman/description/
//Date: 11/23/25
//Difficulty: Medium
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: 
//Notes: note for future:intended much more simpler solution was just to add the special cases to a hash map like IX is equal to 9

std::string intToRoman(int num) {

    static std::vector<std::pair<int,char>> map ={

        {1000,'M'},
        {500,'D'},
        {100,'C'},
        {50,'L'},
        {10,'X'},
        {5,'V'},
        {1,'I'}

    };

        
    int currentNum = 0;
    std::string RomanNum = "";

    std::string tempString = "";

    int digits = 0;

    int tempNum = num;
    std::vector<int> vec;
    while(tempNum!=0){
        vec.insert(vec.begin(),((tempNum%10)*pow(10,digits)));
        digits+=1;
        tempNum/=10;
    }




    while(true){
        
        for(int index = 0; index<vec.size();++index){
            currentNum = vec[index];
            if(currentNum==0){continue;}
            for(int i = 0; i<map.size(); ++i){
                if(currentNum==0){break;}
                if(currentNum/(map[i].first)!=0){
                    tempString = "";
                    int mult = currentNum/map[i].first;
                    for(int x = 0; x<mult; ++x){
                        tempString+=map[i].second;
                    }
                    RomanNum+=tempString;
                    if(mult==0){break;}
                    else{currentNum-=(map[i].first*mult);continue;}
                }
                if(i!=map.size()-1&&(map[i].first)-(map[i+1].first)==currentNum&&map[i+1].first!=currentNum){
                    RomanNum+=map[i+1].second;
                    RomanNum+=map[i].second;
                    break;
                }
                if(i!=map.size()-2&&(map[i].first)-(map[i+2].first)==currentNum){
                    RomanNum+=map[i+2].second;
                    RomanNum+=map[i].second;
                    break;
                }
            }
        }
        return RomanNum;

    }


    return "";
}

int main(){
    int input = 3749;
    std::cout<<intToRoman(input);
    return 0;
}