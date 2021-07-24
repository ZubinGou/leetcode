#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

struct Complex
{
    int real;
    int imaginary;
    bool operator<(const Complex c) const
    {
        long long model = real * real + imaginary * imaginary;
        long long model_c = c.real * c.real + c.imaginary * c.imaginary;
        return model < model_c || model == model_c && imaginary > c.imaginary;
    }
};

int main()
{
    int n;
    string cmd, complex_str;
    priority_queue<Complex> pq;  // C++ 默认为最大堆（大的在前）
    // priority_queue<int, vector<int>, greater<int> > small_heap;  // 最小堆
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> cmd;
            if (cmd == "Pop")
            {
                if (!pq.empty()) {
                    Complex top = pq.top();
                    pq.pop();
                    cout << top.real << "+i" << top.imaginary << endl;
                    cout << "SIZE = " << pq.size() << endl;
                }
                else
                    cout << "empty" << endl;
            }
            else if (cmd == "Insert")
            {
                Complex now;
                // cin >> complex_str;
                // int add_pos = complex_str.find("+");
                // now.real = stoi(complex_str.substr(0, add_pos));
                // now.imaginary = stoi(complex_str.substr(add_pos + 2));
                scanf("%d+i%d", &now.real, &now.imaginary);
                pq.push(now);
                cout <<"SIZE = " << pq.size() << endl;
            }
        }
    }

    return 0;
}