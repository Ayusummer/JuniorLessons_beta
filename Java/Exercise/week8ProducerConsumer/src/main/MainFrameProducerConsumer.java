package main;

// 导入自定义类
import entity.Basket;
import thread.*;
import listener.*;
import macrovalue.MacroValue;

// 导入Java类库
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;


import java.awt.BorderLayout;

import static javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED;
import static javax.swing.ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED;

public class MainFrameProducerConsumer {
    static JFrame frame = null;
    static JLabel label =null;
    static JTextArea textArea = null;
    static Basket basket = null;
    static Thread t1 = null;
    static Thread t2 = null;
    static JScrollPane jScrollPane = null;


    public static void main(String[] args) {
        frame = new JFrame("生产和消费同步问题");

        label = new JLabel();
        label.setText("篮子中馒头的数量是： "+Basket.num);
        frame.add(label, BorderLayout.NORTH);

        textArea = new JTextArea();
        jScrollPane = new JScrollPane(textArea,VERTICAL_SCROLLBAR_AS_NEEDED,
                                        HORIZONTAL_SCROLLBAR_AS_NEEDED);
        frame.add(jScrollPane,BorderLayout.CENTER);

        basket = new Basket();
        t1 = new Thread(new ProducerThread(textArea,label,basket));
        t2 = new Thread(new ConsumerThread(textArea,label,basket));

        JPanel panel = new JPanel();
        JButton button1 = new JButton("生产 开/关");
        button1.addActionListener(new ListenerStopProducerThread(t1));
        JButton button2 = new JButton("消费 开/关");
        button2.addActionListener(new ListenerStopConsumerThread(t2));
        panel.add(button1);
        panel.add(button2);
        frame.add(panel,BorderLayout.SOUTH);

        frame.setVisible(true);
        frame.setSize(400,500);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        t1.start();
        t2.start();


    }
}
