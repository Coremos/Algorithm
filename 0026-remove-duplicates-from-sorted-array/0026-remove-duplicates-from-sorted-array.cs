public class Solution
{
    public int RemoveDuplicates(int[] nums)
    {
        int length = nums.Length;
        int answer = 0;
        int last = -101;
        int index = 0;
        for (int searching = 0; searching < length; searching++)
        {
            if (nums[searching] != last)
            {
                last = nums[searching];
                nums[index++] = last;
                answer++;
            }
        }

        return answer;
    }
}