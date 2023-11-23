//========== 회계 정보 관리 API ==========
const express = require('express');
const router = express.Router();

let transactions = [
    { id: 1, type: 'income', amount: 1000 },
    { id: 2, type: 'expense', amount: -500 },
    
  ];
  
  let students = [
    { id: 1, studentNumber: '202104019', name: 'Jongmin Seo', grade: 3, isPaid: true },
    { id: 2, studentNumber: '202104013', name: 'Ayeong Nam', grade: 3, isPaid: false },
   
  ];
  // 거래 등록 API
router.post('/add-transaction', (req, res) => {
    const { type, amount } = req.body;
  
    if (type && amount !== undefined) {
      const validTypes = ['income', 'expense'];
  
      if (validTypes.includes(type)) {
        const newTransaction = {
          id: transactions.length + 1,
          type,
          amount,
        };
  
        transactions.push(newTransaction);
  
        res.status(201).json({ message: 'success', data: newTransaction });
      } else {
        res.status(400).json({ message: 'Invalid transaction type' });
      }
    } else {
      res.status(400).json({ message: 'type and amount(body) are required' });
    }
  });
// 학회비 납부 여부 조회 API
router.get('/payment-status/:studentId', (req, res) => {
  const studentId = parseInt(req.params.studentId);
  const student = students.find((s) => s.id === studentId);
  if (student) {
    res.status(200).json({ message: 'success', isPaid: student.isPaid });
  } else {
    res.status(404).json({ message: 'student not found' });
  }
});

// 납부된 학회비 수정  API
router.put('/update-payment/:studentId', (req, res) => {
    const studentId = parseInt(req.params.studentId);
    const { isPaid } = req.body;
    const student = students.find((s) => s.id === studentId);
  
    if (student) {
      if (isPaid !== undefined) {
        student.isPaid = isPaid;
        res.status(200).json({ message: 'success', data: student });
      } else {
        res.status(400).json({ message: 'isPaid(body) is required' });
      }
    } else {
      res.status(404).json({ message: 'student not found' });
    }
  });
// 납부된 학회비 삭제 API
router.delete('/delete-payment/:studentId', (req, res) => {
    const studentId = parseInt(req.params.studentId);
    const index = students.findIndex((s) => s.id === studentId);
  
    if (index !== -1) {
      students[index].isPaid = false; // 또는 다른 방식으로 삭제 처리
      res.status(200).json({ message: 'success', data: students[index] });
    } else {
      res.status(404).json({ message: 'student not found' });
    }
  });
// 전체 회계 장부 조회 API
router.get('/ledger', (req, res) => {
  // 가정: transactions 배열이 거래 정보를 담고 있음
  const totalIncome = transactions
  .filter((t) => t.type === 'income')
  .reduce((total, t) => total + t.amount, 0);

const totalExpense = transactions
  .filter((t) => t.type === 'expense')
  .reduce((total, t) => total + t.amount, 0);

const totalBalance = totalIncome + totalExpense;

res.status(200).json({
  message: 'success',
  data: {
    transactions,
    totalIncome,
    totalExpense,
    totalBalance,
  },
});
});

module.exports = router;
