const express = require('express');
const router = express.Router();

// 학우 정보 관리
let students = [
  { id: 1, studentNumber: '202104019', name: 'Jongmin Seo', grade: 3, isPaid: true },
  { id: 2, studentNumber: '202104013', name: 'Ayeong Nam', grade: 3, isPaid: false },
  // Add more student data as needed
];

// ========== 학우 정보 관리 API ==========

// 모든 학우 정보 조회
router.get('/students', (req, res) => {
  res.status(200).json({ message: 'success', data: students });
});

// 특정 학우 정보 조회
router.get('/students/:id', (req, res) => {
  const student = students.find((s) => s.id === parseInt(req.params.id));
  if (student) {
    res.status(200).json({ message: 'success', data: student });
  } else {
    res.status(404).json({ message: 'student not found' });
  }
});

// 신규 학우 등록
router.post('/students', (req, res) => {
  const { studentNumber, name, grade, isPaid } = req.body;
  if (studentNumber && name && grade !== undefined && isPaid !== undefined) {
    const newStudent = {
      id: students.length + 1,
      studentNumber,
      name,
      grade,
      isPaid,
    };
    students.push(newStudent);
    res.status(201).json({ message: 'success', data: newStudent });
  } else {
    res.status(400).json({ message: 'invalid input data' });
  }
});

// 학우 정보 업데이트
router.put('/students/:id', (req, res) => {
  const studentId = parseInt(req.params.id);
  const { studentNumber, name, grade, isPaid } = req.body;
  const index = students.findIndex((s) => s.id === studentId);

  if (index !== -1) {
    students[index] = {
      id: studentId,
      studentNumber: studentNumber || students[index].studentNumber,
      name: name || students[index].name,
      grade: grade !== undefined ? grade : students[index].grade,
      isPaid: isPaid !== undefined ? isPaid : students[index].isPaid,
    };
    res.status(200).json({ message: 'success', data: students[index] });
  } else {
    res.status(404).json({ message: 'student not found' });
  }
});

// 학우 삭제
router.delete('/students/:id', (req, res) => {
  const studentId = parseInt(req.params.id);
  const index = students.findIndex((s) => s.id === studentId);

  if (index !== -1) {
    students.splice(index, 1);
    res.status(200).json({ message: 'success' });
  } else {
    res.status(404).json({ message: 'student not found' });
  }
});

module.exports = router;
