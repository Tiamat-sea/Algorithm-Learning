//
// Created by 16664 on 2023/3/28 下午 10:29.
//
/* 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 如果可以，返回 true ；否则返回 false 。
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 */
#include <iostream>
//#include ""
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash_table[26] = {0};
        for (auto ch : magazine) {
            hash_table[ch - 'a']++;
        }
        for (auto ch : ransomNote) {
            if (hash_table[ch - 'a'] > 0) {
                hash_table[ch - 'a']--;
            }
            else return false;
        }
        return true;
    }
};

int main() {
//    string ransomNote = "a", magazine = "b";
    string ransomNote = "aa", magazine = "aab";
    Solution solution;
    cout << solution.canConstruct(ransomNote, magazine) << endl;
}