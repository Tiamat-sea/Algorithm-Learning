//
// Created by 16664 on 2023/3/28 ���� 10:29.
//
/* ���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�
 * ������ԣ����� true �����򷵻� false ��
 * magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
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