console.log('Hello World');//JS 代码--关注点分离
//用node运行：node index.js
//声明变量:var很少被使用，函数作用域；去掉var之后，变成全局变量
//let 值可以被修改，let 声明的范围是块作用域，
//而 var 声明的范围是函数作用域。
//const 常量
let age = 30;
console.log(age);
//类型：str num bool null undefine
console.log(typeof age);
//字符串：
const uername = "Tom";
console.log("My name is" + uername + "Hello");//旧方法
//模板字符串
console.log(`My name is ${uername}`);
console.log(uername.length);
console.log(uername.toUpperCase());
//分割成数组：
let s = "Hello World";
let ss = "Apple, Computer, Girl";
console.log(s.split(''));//最小分割
console.log(ss.split(", "));//逗号和空格进行分割
