/**
 * @return {number}
 */
var argumentsLength = function(...args) {
    var counter = 0; 
    for(var arg in args)
        counter ++; 
    return counter; 
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
 