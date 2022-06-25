#include <bits/stdc++.h>
using namespace std;

class UnionFind
{

public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n)
    {
        this->parent = vector<int>(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size.push_back(1);
        }
    }
    int getParent(int cur)
    {
        if (this->parent[cur] == cur)
            return cur;

        return parent[cur] = getParent(parent[cur]);
    }

    void makeUnion(int first, int second)
    {
        if (isCon(first, second))
            return;
        int p1 = getParent(first);
        int p2 = getParent(second);

        if (size[p1] > size[p2])
        {
            parent[p2] = p1;
            size[p1] += size[p2];
        }

        else
        {
            parent[p1] = p2;

            size[p2] += size[p1];
        }
    }

    bool isCon(int n1, int n2)
    {
        return getParent(n1) == getParent(n2);
    }
};
