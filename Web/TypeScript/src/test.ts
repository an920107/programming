import * as readline from "readline";
import { stdin, stdout } from "process";

const reader = readline.createInterface({
    input: stdin,
    output: stdout
});

reader.question("Input something...", (str: string) => {
    console.log(str);
});