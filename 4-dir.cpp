#include <bits/stdc++.h>
using namespace std;

vector<int> x{1, -1, 0, 0};
vector<int> y{0, 0, 1, -1};
bool check(int r, int c, vector<vector<int>> &h)
{
    if (r >= 0 && r < h.size() && c >= 0 && c < h[0].size())
        return true;

    return false;
}