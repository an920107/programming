import * as tsImport from 'ts-import';
import * as readline from "readline";
import { stdin, stdout } from "process";

const str = "Input something......";
console.log(str);

const input = document.querySelectorAll("input");
input.forEach(text => {
    console.log(text);
});

let message: (number|string) = "Hello"
let nums = [1, 1, 2, 3, 5]


const func = (x: number): number => {
    return x * x;
}
console.log(func(12));

const min: Function = (x: number, y: number): number => {
    if (x <= y) return x;
    else return y;
};

interface Student {
    name: string;
    id: number;
}

function printStudent(stu: Student) {
    console.log(stu.name);
    console.log(stu.id)
}

let student: Student = {
    name: "Squid", id: 110502000
};

printStudent(student);