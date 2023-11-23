const express = require('express');
const dotenv = require('dotenv');

const morgan = require('morgan');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const fs = require('fs');

const path = require('path');
const multer = require('multer');

dotenv.config();

const PUBLIC = path.join(__dirname, 'public');

const users = {};

const app = express();
app.set('port', process.env.PORT || 3000);

app.use(
    morgan('dev'),
    express.static(PUBLIC),
    express.json(),
    express.urlencoded({ extended: false }),
    cookieParser(process.env.SECRET),
    session({
        resave: false,
        saveUninitialized: false,
        secret: process.env.SECRET,
        cookie: {
            httpOnly: true,
            secure: false
        },
        name: 'session-cookie'
    }));

app.get('/', (_, res) => res.sendFile(path.join(PUBLIC, 'index.html')));
app.get('/users', (_, res) => res.send(JSON.stringify(users)))
app.get('/create', (_, res) => res.sendFile(path.join(PUBLIC, 'create.html')));
app.get('/read', (_, res) => res.sendFile(path.join(PUBLIC, 'read.html')));
app.get('/update', (_, res) => res.sendFile(path.join(PUBLIC, 'update.html')));
app.get('/delete', (_, res) => res.sendFile(path.join(PUBLIC, 'delete.html')));

const DIR = 'data/'
const upload = multer({
    storage: multer.diskStorage({
        destination(req, file, done) {
            done(null, DIR);
        },
        filename(req, file, done) {
            const ext = path.extname(file.originalname);
            done(null, `${req.body.id}${ext}`);
        }
    })
});

// 사용자 정보 추가
app.post('/create', upload.single('image'), (req, res) => {
    const {id, name, birth, gender} = req.body;
    users[id] = {name, birth, gender,'img': req.file?.path ?? ''};
    res.sendFile(path.join(PUBLIC, 'index.html'));
});


// 사용자 정보 조회
app.get('/rid', (req, res) => {
    const { id } = req.query;

    // ID에 해당하는 사용자 정보가 users 객체에 있는지 확인하고 반환
    if (users[id]) {
        const userInfo = users[id];
        res.send(`사용자 정보: ${JSON.stringify(userInfo)}`);
    } else {
        res.send('해당 ID의 사용자를 찾을 수 없습니다.');
    }
});


// 사용자 정보 수정
app.post('/update', upload.single('image'), (req, res) => {
    const userId = req.body.id;
    const { name, birth, gender } = req.body;
    const user = users[userId];
    if (user) {
        // 사용자 정보 업데이트
        user.name = name;
        user.birth = birth;
        user.gender = gender;
        user.img = req.file?.filename ?? user.img;
        res.json({ message: '사용자 정보가 성공적으로 업데이트되었습니다.' });
    } else {
        res.status(404).send('해당 ID의 사용자를 찾을 수 없습니다.');
    }
});

// 사용자 정보 삭제
app.get('/did', (req, res) => {
    const userId = req.query.id;

    if (users[userId]) {
        // 해당 ID에 해당하는 사용자 정보가 있는 경우, 삭제
        delete users[userId];
        res.json({ message: '사용자 정보가 성공적으로 삭제되었습니다.' });
    } else {
        // 해당 ID에 해당하는 사용자 정보가 없는 경우
        res.status(404).json({ error: '해당 ID의 사용자를 찾을 수 없습니다.' });
    }
});


app.listen(app.get('port'), () => console.log(`${app.get('port')} 번 포트에서 대기 중`));
