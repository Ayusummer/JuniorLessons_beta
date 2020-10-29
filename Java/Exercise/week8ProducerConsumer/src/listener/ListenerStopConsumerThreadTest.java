package listener;
// 导入自定义类
import macrovalue.MacroValue;
import thread.ConsumerThread;

// 导入Java类库
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class ListenerStopConsumerThreadTest implements ActionListener {
    ConsumerThread[] threadsConsumer = null;

    public ListenerStopConsumerThreadTest(ConsumerThread[] t) {
        super();
        threadsConsumer = t;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        for(int i = 0; i< MacroValue.MAX_CUSTOMER_NUM; i++) {
           threadsConsumer[i].switchConsumer();
        }
        //this.notifyAll();
    }

}
