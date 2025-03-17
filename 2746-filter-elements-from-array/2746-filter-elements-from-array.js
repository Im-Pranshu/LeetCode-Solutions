/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    // directly by using filter function
    const res = arr.filter(fn);
    return res;
};