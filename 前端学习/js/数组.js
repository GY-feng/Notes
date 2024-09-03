//数组的构造函数
let number = new Array(1, 2, 3, 4)
const f = ['apple', 'orange', 100, false];//数组当中可以有不同类型
f.push('mango');//尾部添加
f.unshift('pears');//头部添加
f.pop();//删除尾部
console.log(f.indexOf('apple'))//获得索引