/**
 * @param {Function} fn
 * @return {Function}
 */

function memoize(func){
  // this will store the previously processed data
  let cache = {}
  return function(...args){
    // it's a possibility that arguments may be multiple
    // so we're converting array into string and then we'll check
    let n = JSON.stringify(args)
    // cache me solved hai to return kardo
    if(n in cache){
      return cache[n]
    }
    // warna calculate solve karo aur cache me store krdo
    else
    {
      // this (current fn) me jo bhi arguments milre hai apply kardo
      let result = func.apply(this, args)
      // cache me store kardo ek bar calculate hone ke bad
      cache[n] = result
      return result
     }
  }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */