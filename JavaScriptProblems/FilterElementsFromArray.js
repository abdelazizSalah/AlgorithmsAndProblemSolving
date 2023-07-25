/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    let ln = arr.length;
    var result = [];
    for (var i = 0; i < ln; i++)
        if (fn(arr[i], i))
            result.push(arr[i]);
    return result;
};