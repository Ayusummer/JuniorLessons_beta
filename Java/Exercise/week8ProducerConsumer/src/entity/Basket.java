package entity;
import macrovalue.MacroValue;

// 缓冲区定义
public class Basket {
    // 缓冲区内当前可放置空间
    public static int putNum = MacroValue.BUFFER_VOLUME;
    // 缓冲区内当前资源量
    public static int getNum = 0;

    // 定义生产者将产出放入缓冲区的函数
    public synchronized int put() {
        // 在上面此处使用的synchronized对类的当前对象加资源锁
        int numPut = 0;
        try{
            // 若缓冲区资源已满则进程进入深睡眠状态
            if(Basket.putNum <= 0)
                this.wait();
            // 线程休眠0~1秒(模拟生产者将产品放入缓冲区的时间)
            Thread.sleep((int)(Math.random() * 1000));
            int num_pre = getNum;
            getNum = getNum + (int)(Math.random() * 10 + 1);  // 生产1~11件物品放入缓冲区
            // 当产出放入缓冲区会导致溢出时放弃溢出部分,缓冲区当前资源量置满
            getNum = Math.min(getNum, 30);
            putNum = MacroValue.BUFFER_VOLUME-getNum;
            numPut = getNum - num_pre;
            // 唤醒一个因当前程序占用的资源陷入深睡眠的线程
            this.notify();
        } catch(InterruptedException e){
            e.printStackTrace();
        }
        return numPut;
    }

    // 定义消费者从缓冲区获取资源的函数
    public  int get(){
        int numPut = 0;
        int num_pre = getNum;
        try{
            synchronized(this) {
                if (Basket.getNum <= 0)
                    this.wait();
                Thread.sleep((int) (Math.random() * 1000));
                getNum = getNum - (int) (Math.random() * 10 + 1);
                getNum = Math.max(0, getNum);
            }
            synchronized(this) {
                putNum = MacroValue.BUFFER_VOLUME - getNum;
                numPut = num_pre - getNum;
            }
            this.notify();  // 唤醒一个因缓冲区满了而沉睡的生产者线程
        } catch (InterruptedException e){
            e.printStackTrace();
        }
        return numPut;
    }
}
