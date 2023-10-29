
#include <span>
#include <ranges>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    vector<int> fullBloomFlowers(const vector<vector<int>>& flowers, const vector<int>& people) const {

        vector<int> startTime(flowers.size());
        vector<int> oneUnitPastEndTime(flowers.size());
        for (int i = 0; i < flowers.size(); ++i) {
            startTime[i] = flowers[i][0];
            oneUnitPastEndTime[i] = flowers[i][1] + 1;
        }

        /*
        Prior to C++20:
        sort(startTime.begin(), startTime.end());
        sort(oneUnitPastEndTime.begin(), oneUnitPastEndTime.end());
         */
        ranges::sort(startTime);
        ranges::sort(oneUnitPastEndTime);

        vector<int> numberOfFlowersInFullBloomWhen_i_personArrives(people.size());
        for (int i = 0; i < people.size(); ++i) {
            numberOfFlowersInFullBloomWhen_i_personArrives[i] =
                    binarySearchForRightmostInsertionIndex(people[i], startTime)
                    - binarySearchForRightmostInsertionIndex(people[i], oneUnitPastEndTime);
        }
        return numberOfFlowersInFullBloomWhen_i_personArrives;
    }

private:
    //Prior to C++20: ...(..., const vector<int>& input) ...
    int binarySearchForRightmostInsertionIndex(int target, span<const int> input) const {
        size_t left = 0;
        /*
        'right = array.size()' instead of 'right = array.size()-1'
        since the method returns the rightmost insertion index.
         */
        size_t right = input.size();

        while (left < right) {
            size_t middle = left + (right - left) / 2;

            if (input[middle] <= target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return left;
    }
};
