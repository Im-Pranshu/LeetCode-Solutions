/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    // return a promise and resolve it after millis
    await new Promise((resolve) => setTimeout(resolve, millis))
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */