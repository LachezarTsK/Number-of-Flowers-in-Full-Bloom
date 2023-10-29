
using System;

public class Solution
{
    public int[] FullBloomFlowers(int[][] flowers, int[] people)
    {
        int[] startTime = new int[flowers.Length];
        int[] oneUnitPastEndTime = new int[flowers.Length];
        for (int i = 0; i < flowers.Length; ++i)
        {
            startTime[i] = flowers[i][0];
            oneUnitPastEndTime[i] = flowers[i][1] + 1;
        }

        Array.Sort(startTime);
        Array.Sort(oneUnitPastEndTime);

        int[] numberOfFlowersInFullBloomWhen_i_personArrives = new int[people.Length];
        for (int i = 0; i < people.Length; ++i)
        {
            numberOfFlowersInFullBloomWhen_i_personArrives[i]
                    = BinarySearchForRightmostInsertionIndex(people[i], startTime)
                    - BinarySearchForRightmostInsertionIndex(people[i], oneUnitPastEndTime);
        }
        return numberOfFlowersInFullBloomWhen_i_personArrives;
    }

    private int BinarySearchForRightmostInsertionIndex(int target, int[] array)
    {
        int left = 0;
        /*
        'right = array.length' instead of 'right = array.length-1'
        since the method returns the rightmost insertion index.
         */
        int right = array.Length;

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (array[middle] <= target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        return left;
    }
}
