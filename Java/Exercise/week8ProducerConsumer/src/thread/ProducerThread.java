package thread;
// 导入自定义类
import entity.Basket;
// 导入java类库
import javax.swing.JTextArea;
import javax.swing.JLabel;


public class Producer implements Runnable{
    public static boolean flag1 = true;
    public static boolean flag2 = true;
    JTextArea textArea = null;
    JLabel label = null;
    Basket basket = null;

    public Producer(JTextArea t, JLabel l, Basket basket) {
        super();
        this.textArea = t;
        this.label = l;
        this.basket = basket;
    }

    // 定义Runnable接口的run()方法
    public void run() {
        while (flag1) {
            if(flag2){
                basket.put();
                label.setText("篮子中馒头的数量是： " + Basket.num);
                textArea.append("线程生产了食物。还剩" + Basket.num + "个食物\n");
            }
            else{
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        }

    }
}
