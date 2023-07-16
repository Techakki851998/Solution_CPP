/*
Sort the People

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        std::vector<std::pair<std::string, int>> people;
        
        for (int i = 0; i < names.size(); i++) {
            people.push_back({names[i], heights[i]});
        }
        
        std::sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        
        std::vector<std::string> sortedNames;
        
        for (const auto& person : people) {
            sortedNames.push_back(person.first);
        }
        
        return sortedNames;
    }
};

int main() {
    std::vector<std::string> names = {"Mary", "John", "Emma"};
    std::vector<int> heights = {180, 165, 170};
    
    Solution solution;
    std::vector<std::string> sortedNames = solution.sortPeople(names, heights);
    
    std::cout << "Sorted names: ";
    for (const auto& name : sortedNames) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
