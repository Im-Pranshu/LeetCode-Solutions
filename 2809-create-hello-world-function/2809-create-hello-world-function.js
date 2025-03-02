/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        let ans = "Hello World";
        return ans;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */