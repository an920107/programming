"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const str = "Input something......";
console.log(str);
const input = document.querySelectorAll("input");
input.forEach(text => {
    console.log(text);
});
let message = "Hello";
let nums = [1, 1, 2, 3, 5];
const func = (x) => {
    return x * x;
};
console.log(func(12));
const min = (x, y) => {
    if (x <= y)
        return x;
    else
        return y;
};
function printStudent(stu) {
    console.log(stu.name);
    console.log(stu.id);
}
let student = {
    name: "Squid", id: 110502000
};
printStudent(student);
