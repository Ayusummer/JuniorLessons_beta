package listener;
// 导入自定义类
import thread.ProducerThread;

// 导入Java类库
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Listener1 implements ActionListener {
    Thread t = null;

    public Listener1(Thread t) {
        super();
        this.t = t;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        ProducerThread.flag2 = !ProducerThread.flag2;
        //this.notifyAll();
    }
}
