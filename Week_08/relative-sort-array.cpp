class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> cache;
        for (int k = 0; k < arr2.size(); k++) {
            cache[arr2[k]] = k;
        }
        quickSort(cache, arr1, 0,arr1.size() - 1);
        return arr1;
    }

    void quickSort(unordered_map<int, int>& cache, vector<int>& arr, int lo, int hi) {
        if (lo < hi) {
            int idx = partition(cache, arr, lo, hi);
            quickSort(cache, arr, lo, idx - 1);
            quickSort(cache, arr, idx + 1, hi);
        }
    }

    int partition(unordered_map<int, int>& cache, vector<int>& arr, int lo, int hi) {
        int rand_idx = rand() % (hi - lo + 1) + lo;
        int pivot = arr[rand_idx];
        swap(arr[hi], arr[rand_idx]);
        int begin = lo;
        for (int k = lo; k < hi; k++) {
            if (less(cache, arr[k], pivot)) {
                if (k != begin) {
                    swap(arr[k], arr[begin]);
                }
                begin++;
            }
        }
        swap(arr[hi], arr[begin]);
        return begin;
    }

    bool less(unordered_map<int, int>& cache, int left, int right) {
        if (cache.count(left) && cache.count(right)) {
            return cache[left] < cache[right];
        } else if (cache.count(left)){
            return true;
        } else if (cache.count(right)) {
            return false;
        } else {
            return left < right;
        }
    }
};