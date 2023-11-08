#include <iostream>
#include <vector>

int findMajorityElement(std::vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = left + (right - left) / 2;

    int leftMajority = findMajorityElement(nums, left, mid);
    int rightMajority = findMajorityElement(nums, mid + 1, right);

    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    int leftCount = 0;
    int rightCount = 0;
    for (int i = left; i <= right; ++i) {
        if (nums[i] == leftMajority) {
            leftCount++;
        } else if (nums[i] == rightMajority) {
            rightCount++;
        }
    }

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

int majorityElement(std::vector<int>& nums) {
    return findMajorityElement(nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums = {3, 3, 4, 2, 3};
    int result = majorityElement(nums);
    std::cout << "Majority Element: " << result << std::endl;

    return 0;
}
