import express, { Express, Request, Response } from 'express';

const port = 5000;
const app: Express = express()

interface Student {
    name: string;
    id: number;
}

const stu: Student = {
    name: 'Squid',
    id: 110502557
}

app.get('/api/student', (request: Request, response: Response) => {
    response.type('application/json');
    response.send(JSON.stringify(stu));
});

app.put

app.listen(port, () => {
    console.log(JSON.stringify(stu));
});
