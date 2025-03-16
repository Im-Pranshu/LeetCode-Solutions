/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const len = arr.length;
    const result = new Array(len);

    for(let i=0; i<len; i++){
        // store transformed element in new array result.
        result[i] = (fn(arr[i], i));
    }

    return result;
};