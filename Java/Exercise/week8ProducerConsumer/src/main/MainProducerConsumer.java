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

public class MainFrameProducerConsumer {
    static JFrame frame = null;
    static JLabel label =null;
    static JTextArea textArea = null;
    public static Basket basket = null;
    public static ProducerThread[] threadsProducer = new ProducerThread[MacroValue.MAX_PRODUCER_NUM];
    public static ConsumerThread[] threadsConsumer = new ConsumerThread[MacroValue.MAX_CUSTOMER_NUM];
    static JScrollPane jScrollPane = null;
    public static int switchProducerNum = 0;
    public static int switchConsumerNum = 0;
    public static JPanel panel;
    public static JButton buttonP;
    public static JButton buttonC;

    // 初始化界面函数
    void init(){
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
        panel = new JPanel();
        buttonP = new JButton("生产 开");
        buttonP.addActionListener(new ListenerStopProducerThread(threadsProducer, frame));
        buttonC = new JButton("消费 开");
        buttonC.addActionListener(new ListenerStopConsumerThread(threadsConsumer, frame));
        panel.add(buttonP);
        panel.add(buttonC);
        frame.add(panel,BorderLayout.SOUTH);

        frame.setVisible(true);
        frame.setSize(400,500);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
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
