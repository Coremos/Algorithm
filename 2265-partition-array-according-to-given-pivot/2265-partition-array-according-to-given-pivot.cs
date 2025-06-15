public class Solution
{
    public int[] PivotArray(int[] nums, int pivot)
    {
        int[] answer = new int[nums.Length];
        int left = 0;
        int right = nums.Length - 1;

        for (int i = 0, j = nums.Length - 1; i < nums.Length; i++, j--)
        {
            if (nums[i] < pivot) answer[left++] = nums[i];
            if (nums[j] > pivot) answer[right--] = nums[j];
        }
        while (left <= right) answer[left++] = pivot;
        return answer;
    }
}