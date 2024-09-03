// Json和对象数组非常相似，区别：每一个case都被打上了双引号
// 对象数组：
const p = [{
    firstName: "john",
    lastName: "Doe",
    age: 30,
    hobbies: ["music", "movies", "sports"],
    address: {
        street: "China",
        city: "GZ",
    },
},
{
    firstName: "Tom",
    lastName: "Doe",
    age: 30,
    hobbies: ["music", "movies", "sports"],
    address: {
        street: "China",
        city: "GZ",
    },
},
{
    firstName: "Arm",
    lastName: "Doe",
    age: 30,
    hobbies: ["music", "movies", "sports"],
    address: {
        street: "China",
        city: "GZ",
    },
},
];
console.log(p[0].address);
const todoJSON = JSON.stringify(p);
console.log(todoJSON);  // 修正拼写错误
