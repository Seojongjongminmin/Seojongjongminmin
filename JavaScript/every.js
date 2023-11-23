// +++ every
Array.prototype.every = function (callback, thisArg) {
    let count = 0;
  
    for (let i = 0; i < this.length; i++) {
      if (!callback.call(thisArg || global, this[i], i, this))
        return false
  
       count += 1;
    }
  
    if (count === this.length)
      return true
  };
  let y=0;
  var arr=[1,3,4,5,2];
  y=arr.every(v => v>= 1);
  console.log('Array.prototype.every:', y);