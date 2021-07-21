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

typedef pair<double, double> JK;

vector<JK> room;

bool cmp(JK a, JK b)
{
    return a.first / a.second > b.first / b.second;
}

int main()
{
    double cat_food;
    int n;
    while (scanf("%lf %d", &cat_food, &n) != EOF)
    {
        if (cat_food == -1 && n == -1)
            break;
        room.clear();
        for (int i = 0; i < n; i++)
        {
            room.push_back({0, 0});
            scanf("%lf %lf", &room[i].first, &room[i].second);
        }
        sort(room.begin(), room.end(), cmp);
        int i = 0;
        double res = 0;
        for (int i = 0; i < n; i++)
        {
            if (cat_food >= room[i].second)
            {
                res += room[i].first;
                cat_food -= room[i].second;
            }
            else
            {
                res += cat_food * room[i].first / room[i].second;
                break;
            }
        }
        printf("%.3f\n", res);
    }

    return 0;
}