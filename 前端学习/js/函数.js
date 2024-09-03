/*

函数实际上是对象，所以函数名本身就是指向函数对象的指针

定义函数时要接收两个参数，并不意味着调用时就传两个参数。你可以传一个、三个，甚至一个也不传，解释器都不会报错.

函数的参数在内部表现为一个数组。函数被调用时总会接收一个数组，但函数并不关心这个数组中包含什么
*/
//基本：
function sum(num1,num2){
    return num1+num2;
}
//箭头函数：
let summ=(num1,num2)=>{
    return num1+num2;
};
console.log(summ(1,2));
//箭头函数适合嵌入函数的使用：
let ints=[1,2,3];
console.log(ints.map((i)=>{return i++;}));
//如果只有一个参数，那也可以不用括号。只有没有参数，或者多个参数的情况下，才需要使用括号

//可以在函数内部访问arguments对象获取参数：(箭头函数不可以)
function sayHi(){
    console.log(arguments[0]+arguments[1]);
}
//没有重载，如果有两个重名函数，那么只会调用后面声明的
//函数定义出现在调用它们的代码之后，引擎也会把函数声明提升到顶部

/*
函数是对象，有属性和方法
属性：
length:命名参数个数
prototype：是保存引用类型所有实例方法的地方，这意味着 toString()、valueOf()等方法实际上都保存在 prototype

方法：
apply
apply()方法接收两个参数：函数内 this 的值和一个参数数组。第二个参数可以是 Array 的实例，但也可以是 arguments 对象
用于调用函数并指定 this 上下文及参数。它通常用于改变函数的 this 值，并传递参数数组。
应用场景：
函数借用：

可以使用 apply 借用其他对象的方法。例如，将数组方法应用于类数组对象。
动态参数传递：

当参数在运行时动态生成时，apply 很有用。你可以将参数作为数组传递给函数。

call
call 方法接受参数列表，而 apply 方法接受一个参数数组。
*/
//函数表达式（匿名函数）
let func=function(){};
let sayHii;
if(true){
    sayHii=function(){
        console.log("Hi");
    }
}