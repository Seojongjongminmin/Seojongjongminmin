// +++ filter
Array.prototype.filter = function (callback, thisArg) {
    const result= []
  
    for (let i = 0; i < this.length; i++) {
      if (callback.call(thisArg || global, this[i], i, this)) {
        result.push(this[i]);
      };
    }
  
    return result;
  };
  let y=0;
  
  y=[1, 2, 3].filter(v => v >= 2);
  console.log('Array.prototype.filter:',y);
  