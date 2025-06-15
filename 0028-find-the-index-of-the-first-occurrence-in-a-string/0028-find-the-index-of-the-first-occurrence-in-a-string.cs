public class Solution
{
    public int StrStr(string haystack, string needle)
    {
        for (int index = 0; index <= haystack.Length - needle.Length; index++)
        {
            if (haystack.Substring(index, needle.Length) == needle)
            {
                return index;
            }
        }
        return -1;
    }
}