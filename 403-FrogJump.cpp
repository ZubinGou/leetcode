#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> res;
    int n;
    
    void jump(int now, int step) {
        cout << "jump " << now << ", " << step << endl;
        res[now] = true;
        for (int i = max(step - 1, 1); i <= step + 1; i++) {
            int next = now + i;
            auto iter = res.find(next);
            if (iter != res.end()) {
                jump(next, i);
            }
        }
    }

public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        for (auto i : stones)
            res[i] = false;
        
        if (res[1] != 1) return false;
        printf("he");
        jump(1, 1);
        return res[stones.back()];
    }
};

int main() {
    Solution sol;
    vector<int> stones({0,1,3,5,6,8,12,17});
    bool res = sol.canCross(stones);
    cout << res << endl;
    return 0;
}