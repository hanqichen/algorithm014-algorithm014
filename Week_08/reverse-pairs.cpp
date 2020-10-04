class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int>& arr, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + ((hi - lo) >> 1);
        int count = mergeSort(arr, lo, mid) + mergeSort(arr, mid + 1, hi);

        vector<int> tmp(hi - lo + 1);
        int left = lo, k = 0, right = mid + 1;
        int inv_right = mid + 1;

        for (;left <= mid; left++) {
            while (inv_right <= hi && arr[left] > (long)2 * arr[inv_right]) inv_right++;
            while (right <= hi && arr[right] < arr[left]) tmp[k++] = arr[right++];
            tmp[k++] = arr[left];
            count += inv_right - mid - 1;
        }

        while (right <= hi) tmp[k++] = arr[right++];
        copy(tmp.begin(), tmp.end(), arr.begin() + lo);
        return count;
    }
};