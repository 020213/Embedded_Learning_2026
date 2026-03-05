int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;  // 慢指针，指向下一个要存放非 val 元素的位置
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;  // 新长度
}