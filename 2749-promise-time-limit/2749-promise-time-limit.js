/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    // Return an asynchronous function that accepts any number of arguments.
    return async function(...args) {
        
        // Return a new Promise to handle asynchronous behavior and time limit.
        return new Promise((resolve, reject) => {

            // Set a timeout to reject the promise if time exceeds the limit `t`.
            setTimeout(() => reject("Time Limit Exceeded"), t);

            // Call the original function `fn` with the provided arguments.
            // If `fn` resolves, the promise is resolved with its result.
            // If `fn` rejects, the promise is rejected with the error.
            fn(...args).then(resolve).catch(reject);
        });
    }
    
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */