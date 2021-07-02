#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    int res = 0;
    int sign_now = 1;
    stack<int> sign;
    sign.push(1);
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            int number = 0;
            while (i < s.size() && s [i] >= '0')
                number = 10 * number - '0' + s[i++];
            i--;
            res += number * sign_now * sign.top();
        }
        else if (c == '+')
            sign_now = 1;
        else if (c == '-') 
            sign_now = -1;
        else if (c == '(') {
            sign.push(sign.top() * sign_now);
            sign_now = 1;
        }
        else if (c == ')') {
            sign.pop();
        }
        cout << "res = " << res << endl;
    }
    return res;
}


int main() {
    // string s(" -(-1)-1");
    // string s("1- -1");
    // string s("2147483647");
    string s("- (3 + (4 + 5))");
    cout << calculate(s) << endl;
    return 0;
}