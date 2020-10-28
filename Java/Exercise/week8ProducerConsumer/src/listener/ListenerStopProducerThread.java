package listener;
// 导入自定义类
import thread.ProducerThread;

// 导入Java类库
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ListenerStopProducerThread implements ActionListener {
    Thread t = null;

    public ListenerStopProducerThread(Thread t) {
        super();
        this.t = t;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        ProducerThread.flag2 = !ProducerThread.flag2;
        //this.notifyAll();
    }
}
