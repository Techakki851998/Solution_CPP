/*
Sorting the Sentence

Companies
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
*/

#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    std::string sortSentence(std::string s) {
        std::vector<std::pair<std::string, int>> words;
        
        // Split the shuffled sentence into individual words
        size_t start = 0;
        size_t end = s.find(' ');
        
        while (end != std::string::npos) {
            std::string word = s.substr(start, end - start);
            int position = word.back() - '0'; // Extract the position number
            words.push_back({word.substr(0, word.size() - 1), position});
            start = end + 1;
            end = s.find(' ', start);
        }
        
        // Process the last word
        std::string word = s.substr(start, end - start);
        int position = word.back() - '0'; // Extract the position number
        words.push_back({word.substr(0, word.size() - 1), position});
        
        // Sort the words based on the position number
        std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        
        // Construct the sorted sentence by concatenating the words
        std::string sortedSentence;
        for (const auto& pair : words) {
            sortedSentence += pair.first + " ";
        }
        
        // Remove the trailing space
        if (!sortedSentence.empty()) {
            sortedSentence.pop_back();
        }
        
        return sortedSentence;
    }
};

int main() {
    std::string s = "is2 sentence4 This1 a3";
    Solution solution;
    std::string sortedSentence = solution.sortSentence(s);
    std::cout << "Sorted sentence: " << sortedSentence << std::endl;
    return 0;
}
