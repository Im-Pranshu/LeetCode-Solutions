/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // promise.all() resolve all promises together and return resolve if all are resolved else if any one rejects it'll reject the promise.
    const [val1, val2] = await Promise.all([promise1, promise2])
    
    return val1 + val2
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */