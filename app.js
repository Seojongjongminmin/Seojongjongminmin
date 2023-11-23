const express = require('express');
const app = express();
app.set('port', 3000);
app.use(express.json());

const studentsRouter = require('./routes/students');
const accountingRouter = require('./routes/accounting')

app.use('/students', studentsRouter);
app.use('/accounting', accountingRouter);

// index
app.get('/', (req, res) => {
    res.send('Hello Express!!');
});

// 404 middleware
app.use((req, res, next)=> {
    res.status(404).json({message : 'api not found (no match entry-point)'});
})

app.listen(app.get('port'), ()=> 
console.log(`${app.get('port')} 번 포트에서 대기 중`));
