/* ------------------------------------------------------------------|
找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了64.71%的用户
*	内存消耗：6.2 MB, 在所有 C++ 提交中击败了90.38%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int longestSubstring(string s, int k) {
    int res = 0;
    int n = s.size();
    //允许出现的最多种类的字符
    for (int i = 1; i <= 26; i++) {
        int l = 0;
        int r = 0;
        //total为目前的字符种类数量
        int total = 0;
        //less为目前少于k个的字符数量
        int less = 0;
        vector<int> cnt(26);
        while (r < n) {
            int tmp = ++cnt[s[r] - 'a'];
            if (tmp == 1) {
                total++;
                less++;
            }
            if (tmp == k) {
                less--;
            }

            while (total > i) {
                int tmp = --cnt[s[l] - 'a'];
                if (tmp == k - 1) {
                    less++;
                }
                if (tmp == 0) {
                    less--;
                    total--;
                }
                l++;
            }
            if (less == 0) {
                res = max(res, r - l + 1);
            }
            r++;
        }
    }
    return res;
}