package thread;
// 导入自定义类
import entity.Basket;
// 导入java类库
import javax.swing.JTextArea;
import javax.swing.JLabel;

public class Consumer implements Runnable{
    public static boolean flag1 = true;
    public static boolean flag2 = true;
    JTextArea consumerTextArea = null;
    JLabel consumerLabel = null;
    Basket basket = null;

    public Consumer(JTextArea t, JLabel l, Basket basket) {
        super();
        this.consumerTextArea = t;
        this.consumerLabel = l;
        this.basket = basket;
    }

    @Override
    public void run() {
        while (flag1) {
            if(flag2){
                basket.get();
                consumerLabel.setText("篮子中馒头的数量是： " + Basket.num);
                consumerTextArea.append("线程消费了食物。还剩" + Basket.num + "个食物\n");
            }else{
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
