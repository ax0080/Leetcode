class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        if(tail - head == 0)
        {
            if(nums[0] == target) return 0;
            else return -1;
        }
        else if(tail - head == 1)
        {
            if(nums[0] == target) return 0;
            else if(nums[1] == target) return 1;
            else return -1;
        }
        
        int mid;
        while(tail - head > 1)
        {
            mid = head + (tail - head)/2;
            if(target > nums[mid]) head = mid + 1;
            else if(nums[mid] > target) tail = mid - 1;
            else return mid;

        }
        

        if(tail - head == 0)
        {
            if(nums[head] == target) return head;
            else return -1;
        }
        else if(tail - head == 1)
        {
            if(nums[head] == target) return head;
            else if(nums[tail] == target) return tail;
            else return -1;
        }
        else return -1;

        
    }
};