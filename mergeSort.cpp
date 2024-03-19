#include <iostream>
#include <vector>

void merge(std::vector<int> &nums, int st, int mid, int end) {
    int i = st;
    int j = mid + 1;
    std::vector<int> sortedNums;
    while (i <= mid && j <= end) {
        if (nums[i] < nums[j]) {
            sortedNums.push_back(nums[i++]);
        }
        else {
            sortedNums.push_back(nums[j++]);
        }
    }

    while (i <= mid) {
        sortedNums.push_back(nums[i++]);
    }

    while (j <= end) {
        sortedNums.push_back(nums[j++]);
    }

    int k = st;
    for (auto &num : sortedNums) {
        nums[k++] = num;
    }
}

void mergeSort(std::vector<int> &nums, int st, int end) {
    if (st >= end) {
        return;
    }

    int mid = (st + end) / 2;
    mergeSort(nums, st, mid);
    mergeSort(nums, mid + 1, end);
    
    merge(nums, st, mid, end);
}


int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    mergeSort(nums, 0, n - 1);

    for (auto &num : nums) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    return 0;
}