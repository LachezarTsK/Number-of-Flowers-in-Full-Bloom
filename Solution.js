
/**
 * @param {number[][]} flowers
 * @param {number[]} people
 * @return {number[]}
 */
var fullBloomFlowers = function (flowers, people) {

    const startTime = new Array(flowers.length);
    const oneUnitPastEndTime = new Array(flowers.length);
    for (let i = 0; i < flowers.length; ++i) {
        startTime[i] = flowers[i][0];
        oneUnitPastEndTime[i] = flowers[i][1] + 1;
    }

    startTime.sort((x, y) => x - y);
    oneUnitPastEndTime.sort((x, y) => x - y);

    const numberOfFlowersInFullBloomWhen_i_personArrives = new Array(people.length);
    for (let i = 0; i < people.length; ++i) {
        numberOfFlowersInFullBloomWhen_i_personArrives[i] =
                binarySearchForRightmostInsertionIndex(people[i], startTime)
                - binarySearchForRightmostInsertionIndex(people[i], oneUnitPastEndTime);
    }
    return numberOfFlowersInFullBloomWhen_i_personArrives;
};


/**
 * @param {number} target
 * @param {number[]} array
 * @return {number}
 */
function binarySearchForRightmostInsertionIndex(target, array) {
    let left = 0;
    /*
     'right = array.length' instead of 'right = array.length-1'
     since the method returns the rightmost insertion index.
     */
    let right = array.length;

    while (left < right) {
        let middle = left + Math.floor((right - left) / 2);

        if (array[middle] <= target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return left;
}
