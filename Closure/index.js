// 再添加私有方法
function createCounter(counterName) {
  var counter = 0;
  function display() {
    console.log("Number of " + counterName + ": " + counter);
  }
  function increment() {
    counter = counter + 1;
    display();
  };
  function decrement() {
    counter = counter - 1;
    display();
  };
  return {
    increment: increment,
    decrement: decrement
  };
}
var dogsCounter = createCounter("dogs");
dogsCounter.increment(); // Number of dogs: 1
dogsCounter.increment(); // Number of dogs: 2
dogsCounter.decrement(); // Number of dogs: 1

// // 再添加decrement方法
// function createCounter(counterName) {
//   var counter = 0;
//   function increment() {
//     counter = counter + 1;
//     console.log("Number of " + counterName + ": " + counter);
//   };
//   function decrement() {
//     counter = counter - 1;
//     console.log("Number of " + counterName + ": " + counter);
//   };
//   return {
//     increment: increment,
//     decrement: decrement
//   };
// }
// var dogsCounter = createCounter("dogs");
// dogsCounter.increment(); // Number of dogs: 1
// dogsCounter.increment(); // Number of dogs: 2
// dogsCounter.decrement(); // Number of dogs: 1

// // 优化计数器调用方式
// var dogCounter = createCounter("dogs");
// dogCounter.increment(); // Number of dogs: 1

// function createCounter(counterName) {
//   var counter = 0;
//   function increment() {
//     counter = counter + 1;
//     console.log("Number of " + counterName + ": " + counter);
//   };
//   return { increment: increment };
// }

// // 为计数器命名
// var catCounter = createCounter("cats");
// var dogCounter = createCounter("dogs");
// catCounter(); // Number of cats: 1
// catCounter(); // Number of cats: 2
// dogCounter(); // Number of dogs: 1

// function createCounter(counterName) {
//   var counter = 0;
//   function increment() {
//     counter = counter + 1;
//     console.log("Number of " + counterName + ": " + counter);
//   }
//   return increment;
// }

// // 使用闭包实现多个计数器
// function createCounter() {
//   var counter = 0;
//   function increment() {
//     counter = counter + 1;
//     console.log("Number of events: " + counter);
//   }
//   return increment;
// }
// var counter1 = createCounter();
// var counter2 = createCounter();
// counter1(); // Number of events: 1
// counter1(); // Number of events: 2
// counter2(); // Number of events: 1
// counter1(); // Number of events: 3