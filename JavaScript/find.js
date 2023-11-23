// +++ find
Array.prototype.find = function (callback, thisArg) {
    for (let i = 0; i < this.length; i++) {
      if (callback.call(thisArg || global, this[i], i, this)) {
        return this[i];
      }
    }
  };
  let y=0;
  y=[1, 2, 3, 4, 5].find(v => v % 2 === 0);
  console.log('Array.prototype.find:', y);