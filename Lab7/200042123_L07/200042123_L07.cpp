
#include <iostream>
#include<vector>
#include<map>

using namespace std;


int reversePair(int l, int r, vector<int>& nums)
{
    int cnt = 0;
    vector<int> temp;

    int i = l;
    int mid = l + (r - l) / 2;
    int j= mid+1;

    while (i <= mid && j <= r) {
        if (nums[i] > 2 * nums[j]) {
            cnt++;
            j++;
        }
        else {
            i++;
        }
    }

    //merge(nums.begin() + l,nums.begin()+mid,nums.begin()+mid+1,nums.begin()+r,temp.begin());

    i = l;
    j = mid + 1;


    while (i <= mid && j <= r)
    {
        if (nums[i] < nums[j]) temp.push_back(nums[i++]);
        else temp.push_back(nums[j++]);

    }
    while (i <= mid)temp.push_back(nums[i++]);
    while (j <= r) temp.push_back(nums[j++]);



    int in = 0;

    for (int k = l;k <= r;k++)
        nums[k] = temp[in++];
    
    return cnt;
}

int call(int l, int r, vector<int>& nums)
{
    int count = 0;

    if (l < r)
    {
        int mid = (l + r) / 2;

        count = call(mid + 1, r, nums)+call(l, mid, nums)+reversePair(l,r,nums);
    }

    return count;
}


int main()
{
    vector<int> nums;
    int cnt;
    cnt = call(0, nums.size() - 1, nums);
	return 0;
}

