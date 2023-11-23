Array.prototype.flatMap = function (callback) {
  const result = [];

  for (let i = 0; i < this.length; i++) {
    result.push(callback(this[i])[0]);
  }

  return result;
};

let y =0;
var arr = [23,45,21,25,32];
y=arr.flatMap((v)=> [v * v]);
console.log('Array.prototype.flatMap:', y);