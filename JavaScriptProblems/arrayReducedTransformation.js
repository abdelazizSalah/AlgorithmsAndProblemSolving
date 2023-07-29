/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
    // If the length of the array is 0, it should return init.
    if (nums.length == 0)
        return init;

    var val = init;
    for (var i = 0; i < nums.length; i++) {
        val = fn(val, nums[i]);
    }

    return val;
};