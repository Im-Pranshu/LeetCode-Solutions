/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    // here functions is array fn having n no of function
    return function(x) {
        // traverse fn array and visit all function from right to left order
        for(let i = functions.length - 1; i>=0; i--){
            // evaluation is right to left 
            // values of evalution for all fn call 
            // will be stored in x
            x = functions[i](x)
        }
        // finally all functions are called
        // values is updated in x now return val
        return x
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */