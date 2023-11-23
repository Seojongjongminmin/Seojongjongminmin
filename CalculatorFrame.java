import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.Socket;

public class CalculatorFrame extends JFrame {
    String operand;
    String operator;

    // 클라이언트 소켓과 입출력 스트림
    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;

    public CalculatorFrame() {
        // Frame 설정
        setSize(500, 500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);

        // GUI 구성 요소 생성
        JTextField textField = new JTextField();
        JPanel panel = new JPanel(new GridLayout(4, 4));

        String[] buttons = { "7", "8", "9", "-", "4", "5", "6", "+", "1", "2", "3", "*", "/", "0", "Clear", "=" };

        for (String button : buttons) {
            JButton btn = new JButton(button);
            btn.setFont(new Font("Arial", Font.PLAIN, 30));
            btn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    handleButtonClick(button, textField);
                }
            });
            panel.add(btn);
        }

        // 컴포넌트 추가
        add(textField, BorderLayout.NORTH);
        add(panel);

        // 서버에 연결
        try {
            socket = new Socket("localhost", 9999);
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void handleButtonClick(String button, JTextField textField) {
        if (button.charAt(0) >= '0' && button.charAt(0) <= '9') {
            textField.setText(textField.getText() + button);
        } else if (button.equals("Clear")) {
            textField.setText("");
            operand = "";
            operator = "";
        } else if (button.equals("=")) {
            long op1 = Long.valueOf(operand);
            long op2 = Long.valueOf(textField.getText());

            if (operator.equals("+")) {
                textField.setText(String.valueOf(op1 + op2));
            } else if (operator.equals("-")) {
                textField.setText(String.valueOf(op1 - op2));
            } else if (operator.equals("*")) {
                textField.setText(String.valueOf(op1 * op2));
            } else if (operator.equals("/")) {
                textField.setText(String.valueOf(op1 / op2));
            }

            // 결과를 서버로 전송
            out.println(textField.getText());
            operand = "";
            operator = "";
        } else {
            operand = textField.getText();
            operator = button;
            textField.setText("");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CalculatorFrame frame = new CalculatorFrame();
            frame.setVisible(true);
        });
    }
}
