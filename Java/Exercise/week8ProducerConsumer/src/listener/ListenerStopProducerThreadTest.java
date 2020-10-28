package listener;
// 导入自定义类
import macrovalue.MacroValue;
import thread.ProducerThread;

// 导入Java类库
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


// 线程生产开关(实现方式是循环调用生产线成中的开关函数,因此会有一定延迟)
public class ListenerStopProducerThreadTest implements ActionListener{
    static ProducerThread[] threadsProducer =null;

    public ListenerStopProducerThreadTest(ProducerThread[] t) {
        super();
        threadsProducer = t;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        for(int i = 0; i< MacroValue.MAX_PRODUCER_NUM; i++) {
            threadsProducer[i].switchProducer();
        }
        //this.notifyAll();
    }
}

