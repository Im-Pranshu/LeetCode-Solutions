/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        // Method to check for eql
        toBe: (v) => v===val || (() => {throw new Error("Not Equal")})(),
        // Method to check for un-eql
        notToBe: (v) => v!==val || (() => {throw new Error("Equal")})()
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */