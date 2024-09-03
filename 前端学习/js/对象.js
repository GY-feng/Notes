//js对象是有属性和方法的数据，表示为键值对的组合
const person = {
    firstName: "john",
    lastName: "Doe",
    age: 30,
    hobbies: ["music", "movies", "sports"],
    address: {
        street: "China",
        city: "GZ",
    },
};
console.log(person);
console.log(person.firstName, person.lastName);
console.log(person.address.city);
//解构：
const {
    firstName,
    lastName,
    address: { city }
} = person;//相当于用同名的变量将值从person当中抽取出来
console.log(city);
//添加新的属性：
person.email = "qq.com";

