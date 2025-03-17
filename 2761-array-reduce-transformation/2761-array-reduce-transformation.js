/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    // make this init as total to store final result
    let total = init;
    // iterate in whole array to reduce
    for(let i=0; i<nums.length; i++){
        // iterate all elements and reduce in total
        total = fn(total, nums[i]);
    }
    // return total reduced value
    return total;
};