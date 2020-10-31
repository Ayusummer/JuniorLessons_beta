package main;
// 导入自定义类
import entity.Basket;
import macrovalue.MacroValue;
import thread.*;
import listener.*;

// 导入Java类库
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


import java.awt.BorderLayout;

import static javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED;
import static javax.swing.ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED;

public class MainFrameProducerConsumerTest {
    static JFrame frame = null;
    static JLabel label =null;
    static JTextArea textArea = null;
    static Basket basket = null;
    static ProducerThread[] threadsProducer = new ProducerThread[MacroValue.MAX_PRODUCER_NUM];
    static ConsumerThread[] threadsConsumer = new ConsumerThread[MacroValue.MAX_CUSTOMER_NUM];
    static JScrollPane jScrollPane = null;


    public static void main(String[] args) {
        frame = new JFrame("生产和消费同步问题");

        label = new JLabel();
        label.setText("篮子中馒头的数量是： "+Basket.getNum);
        frame.add(label, BorderLayout.NORTH);

        textArea = new JTextArea();
        jScrollPane = new JScrollPane(textArea,VERTICAL_SCROLLBAR_AS_NEEDED,
                HORIZONTAL_SCROLLBAR_AS_NEEDED);
        frame.add(jScrollPane,BorderLayout.CENTER);

        basket = new Basket();
        for(int i=0; i<MacroValue.MAX_PRODUCER_NUM; i++){
            threadsProducer[i] = new ProducerThread(textArea,label,basket);
        }
        for(int i=0; i<MacroValue.MAX_CUSTOMER_NUM; i++) {
            threadsConsumer[i] = new ConsumerThread(textArea, label, basket);
        }
        JPanel panel = new JPanel();
        JButton button1 = new JButton("生产 开/关");
        button1.addActionListener(new ListenerStopProducerThreadTest(threadsProducer));
        JButton button2 = new JButton("消费 开/关");
        button2.addActionListener(new ListenerStopConsumerThreadTest(threadsConsumer));
        panel.add(button1);
        panel.add(button2);
        frame.add(panel,BorderLayout.SOUTH);

        frame.setVisible(true);
        frame.setSize(400,500);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 创建一个线程池
        ExecutorService eService = Executors.newCachedThreadPool();
        // 将线程加入线程池
        for(int i=0; i<MacroValue.MAX_PRODUCER_NUM; i++) {
            eService.submit(threadsProducer[i]);
        }
        for(int i=0; i<MacroValue.MAX_CUSTOMER_NUM; i++) {
            eService.submit(threadsConsumer[i]);
        }
        eService.shutdown();
    }
}
