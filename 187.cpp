#include "regular_headers.hpp"

template <class T>
void printbybit(const T &ob) {
    char *p_e = (char *)&ob;
    char *p = p_e + sizeof(T) - 1;
    for (; p >= p_e; p--) {
        for (int i = 7; i >= 0; i--) {
            cout << (((*p) & (1 << i)) ? 1 : 0);
        }
    }
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<int> nums(s.size());
    for (int i = 0; i < s.size(); i++) {
        int temp = 0;
        switch (s[i]) {
        case 'A': temp = 0; break;
        case 'C': temp = 1; break;
        case 'G': temp = 2; break;
        case 'T': temp = 3; break;
        default: break;
        }
        nums[i] = temp;
    }
    unordered_map<int, int> umap;
    vector<string> ans;
    int L = 10;
    int R = 4;
    int RL = pow(R, L - 1);
    int left = 0, right = 0;
    int hash_num = 0;
    while (right < nums.size()) {
        hash_num *= R;
        hash_num += nums[right];
        right++;
        if (right - left == L) {
            if (umap[hash_num] == 1) {
                ans.push_back(s.substr(left, L));
            }
            umap[hash_num]++;
            hash_num -= nums[left] * RL;
            left++;
        }
    }
    return ans;
}

int main() {
    string s{"AAAAAAAAAAAAA"};
    findRepeatedDnaSequences(s);
}