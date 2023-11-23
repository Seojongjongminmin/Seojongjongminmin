Array.prototype.some = function (callback, thisArg) {
  let count = 0;

  for(let i = 0; i < this.length; i++) {
    if(callback.call(thisArg || global, this[i], i, this))
      return true

  count =+ 1;
  }

  if(count === this.length)
    return false
};
let y = 0;
y =[1,3,5,7,5].some(v => v % 2 === 0);
console.log('Array.prototype.some:',y);
