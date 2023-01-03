"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const port = 5000;
const app = (0, express_1.default)();
const stu = {
    name: 'Squid',
    id: 110502557
};
app.get('/api/student', (request, response) => {
    response.type('application/json');
    response.send(JSON.stringify(stu));
});
app.put;
app.listen(port, () => {
    console.log(JSON.stringify(stu));
});
