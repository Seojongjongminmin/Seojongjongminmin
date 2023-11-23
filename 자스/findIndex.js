// +++ findIndex
Array.prototype.findIndex = function (callback, thisArg) {
    for (let i =0; i < this.length; i++) {
      if (callback.call(thisArg || globalThis, this[i], i, this)) {
        return i;
      }
    }
    return '-1';
  };
  let y=0;
  var arr =[1,3,2,5,4];
  y= arr.findIndex(v => v % 5===0);
  console.log('Array.prototype.findindex:', y);
  