package listener;
// 导入自定义类
import thread.ConsumerThread;

// 导入Java类库
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Listener2 implements ActionListener {
    Thread t = null;

    public Listener2(Thread t) {
        super();
        this.t = t;
    }

    @Override
    public void actionPerformed(ActionEvent e) {


        ConsumerThread.flag2 = !ConsumerThread.flag2;
        //this.notifyAll();
    }

}
