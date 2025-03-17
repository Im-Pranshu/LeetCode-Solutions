/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const res = [];
    for(let i=0; i<arr.length; i++){
        // if value is greater than 10 then
        // it will return true and push it to arr.
        if(fn(arr[i],i)){
            res.push(arr[i]);
        }
    }
    
    return res;
};