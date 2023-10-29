
import java.util.Arrays;

public class Solution {

    public int[] fullBloomFlowers(int[][] flowers, int[] people) {

        int[] startTime = new int[flowers.length];
        int[] oneUnitPastEndTime = new int[flowers.length];
        for (int i = 0; i < flowers.length; ++i) {
            startTime[i] = flowers[i][0];
            oneUnitPastEndTime[i] = flowers[i][1] + 1;
        }

        Arrays.sort(startTime);
        Arrays.sort(oneUnitPastEndTime);

        int[] numberOfFlowersInFullBloomWhen_i_personArrives = new int[people.length];
        for (int i = 0; i < people.length; ++i) {
            numberOfFlowersInFullBloomWhen_i_personArrives[i]
                    = binarySearchForRightmostInsertionIndex(people[i], startTime)
                    - binarySearchForRightmostInsertionIndex(people[i], oneUnitPastEndTime);
        }
        return numberOfFlowersInFullBloomWhen_i_personArrives;
    }

    private int binarySearchForRightmostInsertionIndex(int target, int[] array) {
        int left = 0;
        /*
        'right = array.length' instead of 'right = array.length-1'
        since the method returns the rightmost insertion index.
         */
        int right = array.length;

        while (left < right) {
            int middle = left + (right - left) / 2;

            if (array[middle] <= target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return left;
    }
}
