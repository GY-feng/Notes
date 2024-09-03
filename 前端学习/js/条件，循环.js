const x = 110;
if (x === 110)//三等号在类型相同并且值相同的情况才True，双等号在比较两个值之前会进行 类型转换
{
    console.log("x is 110");
}
else if (x > 10)
{
    console.log("x is bigger than 110");
}
else
{
    console.log("x is not 110");

}
//三目表达式
const color = x > 10 ? "red" : "blue";
//真的适合输出red，假则blue
switch (color) {
    case "red":
        break;
    case "blue":
        break;
    default:
        break;
}
//FOR
for (let i = 0; i < 10; i++)
{
    console.log(i);
}
let i = 10;
while (i < 10) {
    i++;
    console.log(i);
}
//对象数组+循环：
const pp = [{
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
for (let i = 0; i < pp.length; i++)
{
    console.log(pp[i].address);
}
//或者
for (let todo of pp) {
    console.log(pp[i].address);
}