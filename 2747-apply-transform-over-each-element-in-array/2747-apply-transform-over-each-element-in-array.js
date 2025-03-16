/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const result = new Array();

    for(let i=0; i<arr.length; i++){
        // store transformed element in new array result.
        result[i] = (fn(arr[i], i));
    }

    return result;
};