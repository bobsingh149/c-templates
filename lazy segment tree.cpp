#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> tree;
    vector<int> lazy;
    vector<int> vals;
    SegmentTree(vector<int> &nums)
    {
        tree = vector<int>(4 * nums.size(), 0);
        lazy = tree;
        vals = nums;
    }

    void construct(int cur, int l, int h)
    {
        if (l == h)
        {
            tree[cur] = vals[l];
            return;
        }

        int m = (l + h) / 2;

        construct(2 * cur + 1, l, m);

        construct(2 * cur + 2, m + 1, h);

        tree[cur] = tree[cur * 2 + 1] + tree[cur * 2 + 2];
    }

    void update(int cur, int l, int h, int left, int right, int val)
    {

        if (lazy[cur] != 0)
        {
            int size = h - l + 1;

            tree[cur] += lazy[cur] * size;

            if (l != h)
            {
                lazy[2 * cur + 1] += lazy[cur];
                lazy[2 * cur + 2] += lazy[cur];
            }

            lazy[cur] = 0;
        }

        if (h < left || l > right)
            return;

        if (l >= left && h <= right)
        {

            int size = h - l + 1;

            tree[cur] += lazy[cur] * size;

            lazy[cur] = 0;

            tree[cur] += val * size;

            if (l != h)
            {
                lazy[2 * cur + 1] += val;
                lazy[2 * cur + 2] += val;
            }

            return;
        }

        int m = (l + h) / 2;

        update(2 * cur + 1, l, m, left, right, val);

        update(2 * cur + 2, m + 1, h, left, right, val);

        tree[cur] = tree[2 * cur + 1] + tree[2 * cur + 2];
    }

    int rangeSum(int cur, int l, int h, int left, int right)
    {
        if (lazy[cur] != 0)
        {
            int size = h - l + 1;

            tree[cur] += lazy[cur] * size;

            if (l != h)
            {
                lazy[2 * cur + 1] += lazy[cur];
                lazy[2 * cur + 2] += lazy[cur];
            }

            lazy[cur] = 0;
        }

        if (h < left || l > right)
            return 0;

        if (l >= left && h <= right)
        {

            return tree[cur];
        }

        int m = (l + h) / 2;

        int l = rangeSum(2 * cur + 1, l, m, left, right);

        int r = rangeSum(2 * cur + 2, m + 1, h, left, right);

        return l + r;
    }
};
