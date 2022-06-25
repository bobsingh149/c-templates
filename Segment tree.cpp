#include <bits/stdc++.h>
using namespace std;

class Segment
{
private:
    vector<int> tree;
    vector<int> arr;
    void construct(int cur, int l, int r)
    { // cout<<"cur "<<cur<<" l "<<l<<" r "<<r<<endl;
        if (l == r)
        {
            tree[cur] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        construct(2 * cur + 1, l, mid);
        construct(2 * cur + 2, mid + 1, r);

        tree[cur] = tree[2 * cur + 1] + tree[2 * cur + 2];
    }

    int getval(int cur, int l, int r, int left, int right)
    {

        if (r < left || l > right)
            return 0;

        if (l >= left && r <= right)
        {
            return tree[cur];
        }

        int mid = (l + r) / 2;

        int leftsegsum = getval(2 * cur + 1, l, mid, left, right);

        int rightsegsum = getval(2 * cur + 2, mid + 1, r, left, right);

        return leftsegsum + rightsegsum;
    }

    void upd(int cur, int l, int r, int diff, int idx)
    {
        // cout<<"cur "<<cur<<" l "<<l<<" r "<<r<<" idx "<<idx<<endl;
        if (idx < l || idx > r)
            return;
        if (idx >= l && idx <= r)
        {
            tree[cur] += diff;
            // cout<<"updating"<<endl;
        }

        if (l == r)
            return;

        int mid = (l + r) / 2;

        upd(2 * cur + 1, l, mid, diff, idx);

        upd(2 * cur + 2, mid + 1, r, diff, idx);
    }

public:
    Segment(vector<int> &nums)
    {

        arr = nums;
        tree = vector<int>(nums.size() * 4);
        // cout<<"call1 "<<endl;
        this->construct(0, 0, nums.size() - 1);
        // cout<<"ret1 "<<endl;
    }

    int get(int l, int r)
    { // cout<<"call2 "<<endl;
        int val = getval(0, 0, arr.size() - 1, l, r);
        // cout<<val<<endl;
        return val;
    }

    void update(int idx, int val)
    { // cout<<"call3 "<<endl;
        int diff = val - arr[idx];
        arr[idx] = val;
        upd(0, 0, arr.size() - 1, diff, idx);
        // cout<<"ret3 "<<endl;
    }
};