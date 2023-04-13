//
// Created by 16664 on 2023/3/28 下午 01:49.
//
/* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (auto a : s) {
            record[a - 'a']++;
        }
        for (auto a : t) {
            record[a - 'a']--;
        }
        for (auto i : record) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "rat", t = "car";
//    string s = "anagram", t = "nagaram";
    Solution solution;
    cout << solution.isAnagram(s, t) << endl;
}