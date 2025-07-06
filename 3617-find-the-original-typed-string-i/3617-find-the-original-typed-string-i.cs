public class Solution {
    public int PossibleStringCount(string word) {
        char last = word[0];
        int count = 1;
        int answer = 1;

        for (int i = 1; i < word.Length; i++)
        {
            if (word[i] != last)
            {
                if (count > 1)
                    answer += count - 1;
                last = word[i];
                count = 1;
            }
            else
            {
                count++;
            }
        }

        if (count > 1)
            answer += count - 1;

        return answer;
    }
}