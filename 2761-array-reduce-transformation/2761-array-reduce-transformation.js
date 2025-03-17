/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    // using reduce function to get total.
    let total = nums.reduce(fn, init, nums);
    return total
};