let x = do {
  let t = 22;
  t * t + 1;
};
console.log(x);

// function f() { console.log('I am outside!'); }
//
// (function () {
//   if (false) {
//     // 重复声明一次函数f
//     function f() { console.log('I am inside!'); }
//   }
//
//   f();
// }());

// function f1() {
//   let n = 5;
//   if (true) {
//     let n = 10;
//   }
//   console.log(n); // 5
// }
//
// f1();

// for (let i = 0; i < 3; i++) {
//   debugger;
//   let i = 'abc';
//   console.log(i);
// }

// let a = [];
// for (let i = 0; i < 10; i++) {
//   a[i] = function () {
//     console.log(i);
//   };
// }
// a[6](); // 10


// var a = [];
// for (var i = 0; i < 10; i++) {
//   a[i] = function () {
//     console.log(i);
//   };
// }
// a[6](); // 10

// let [foo] = [];
//
// console.log(foo);
