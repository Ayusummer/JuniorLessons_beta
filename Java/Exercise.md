# 前言
- 笔记中涉及的Java规约大多是阿里巴巴Java开发手册(嵩山版)中的规约
  - 以下简称(**嵩山版规约**)

---
## 实验环境
- 软件:
  - IDEAU2020.2
- 编码方案
  - 没有特殊声明的情况下都是UTF-8
  

---
# 生产者消费者
- 第4次第8周作业
- 编写代码完成生产者消费者程序，要求：
    - 1、有多个生产者和多个消费者
    - 2、每一次的生产和消费的数量都要能够显示

## 随笔
### Math.random()
- 依赖包:
  ```Java
  import java.util.Random;
  ```
- 功能
  - 默认产生大于等于0.0且小于1.0之间的随机double型随机数
    - $0.0<=Math.random()<1.0$

---
### Thread.sleep()
- Thread.sleep()是Thread类的一个静态方法，使当前线程休眠，进入阻塞状态（暂停执行）
  - 如果线程在睡眠状态被中断，将会抛出IterruptedException中断异常。
- 主要方法如下：
  ```Java
  sleep(long millis)  线程睡眠 millis 毫秒
  sleep(long millis, int nanos)  线程睡眠 millis 毫秒 + nanos 纳秒
  ```

---
### 导入包
- 导入所处包同级目录下包的类
  ```Java
  import 包名.类名
  ```
- 包名(嵩山版规约)
  - 【强制】包名统一使用**小写**，点分隔符之间有且仅有一个自然语义的英语单词。包名统一使用单数形式，但是类名如果有复数含义，类名可以使用复数形式。
    - 正例：
      ```Java
      // 应用工具类包名为:
      com.alibaba.ei.kunlun.aap.util
      //类名为 :
      MessageUtils  //（此规则参考 spring 的框架结构）
      ```
- 类名(嵩山版规约)
  - 【强制】类名使用 UpperCamelCase 风格，但以下情形例外：DO / BO / DTO / VO / AO / PO / UID 等。
    - 正例：  
      ForceCode / UserDO / HtmlDTO / XmlService / TcpUdpDeal / TaPromotion
    - 反例：  
      forcecode / UserDo / HTMLDto / XMLService / TCPUDPDeal / TAPromotion
- 方法名(嵩山版规约)
  - 【强制】方法名、参数名、成员变量、局部变量都统一使用 lowerCamelCase 风格。
    - 正例:  
      localValue / getHttpMessage() / inputUserId 
- 常量名(嵩山版规约)
  - 【强制】常量命名全部大写，单词间用下划线隔开，力求语义表达完整清楚，不要嫌名字长。
    - 正例：  
      MAX_STOCK_COUNT / CACHE_EXPIRED_TIME
    - 反例：  
      MAX_COUNT / EXPIRED_TIME
- 抽象/异常/测试类名
  - 【强制】抽象类命名使用 Abstract 或 Base 开头；
  - 异常类命名使用 Exception 结尾；
  - 测试类命名以它要测试的类的名称开始，以 Test 结尾。
- 数组定义
  - 【强制】类型与中括号紧挨相连来表示数组。
    - 正例：  
      ```Java
      //定义整形数组 
      int[] arrayDemo。
      ```
    - 反例：  
      在 main 参数中，使用 String args[]来定义。

---
### 两数较大值/较小值
```Java
Math.min(num1, num2);
Math.max(num1, num2);
```

---
### @Override
- [参考文章](https://www.cnblogs.com/ttzz/p/8455325.html)
- 作用
  - 作为注释，帮助自己检查是否正确的复写了父类中已有的方法
  - 便于别人理解代码
  - 编译器可以给你验证@Override下面的方法名是否是你父类中所有的，如果没有则报错．
    - 自己重写接口方法或者父类方法时写错方法名的话编译的时候会报错
      - 相应的,不加@Override的话若是实例的接口的方法写错的话编译时还能报没有实例化使用接口中的所有方法
        - 但是若是重写父类方法写错方法名的话编译时会被认为是该子类定义的新的方法而不报错

---
### JFrame
```Java
baseFrame = new JFrame("棋盘");
baseFrame.setVisible(true);    // 容器可见
baseFrame.setSize(600,700);    // 设置容器大小
// 设置容器居中显示
baseFrame.setLocationRelativeTo(null);   
// 按X关闭窗口   
baseFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
```
- ```Java
  JFrame.pack()
  ```
  - [参考链接](https://blog.csdn.net/sherlocksy/article/details/80110773)
  - pack() 调整此窗口的大小，以适合其子组件的首选大小和布局
  - 单独使用setSize()时，不能使用pack()，否则按照pack()自动适配
  - 单独使用pack()时，是按照组件的大小自动适配的
  - 单独使用setPreferredSize()时，设置的大小无效，必须在后面添加pack()配合显示，否则设置效果不生效
    - ```Java
      setPreferredSize()
      ```
      - 所属类
        ```Java
        java.awt.Component
        ```
      - 函数声明
        ```Java
        public void setPreferredSize(Dimension preferredSize)
        ```
        - 将此组件的首选大小设置为常量值。 随后电话getPreferredSize总是返回此值。 将首选大小设置为null可恢复默认行为。
        - preferredSize - 新的首选大小，或null

---
### 滚动窗格 JScrollPane
- 创建一个水平与垂直滚动条在需要时才显示的,以一个文本域为视口的滚动窗格
  ```Java
  import javax.swing.JTextArea;
  import javax.swing.JScrollPane;
  import static javax.swing.ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED;
  import static javax.swing.ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED;
  static JTextArea textArea = null;
  static JScrollPane jScrollPane = null;
  textArea = new JTextArea();
  jScrollPane = new JScrollPane(textArea,VERTICAL_SCROLLBAR_AS_NEEDED,HORIZONTAL_SCROLLBAR_AS_NEEDED);
  ```

---
### Synchronized
- [原文链接](https://blog.csdn.net/zjy15203167987/article/details/82531772)
---
#### 为什么要使用synchronized
- 在并发编程中存在线程安全问题，主要原因有：
  - 1.存在共享数据 
  - 2.多线程共同操作共享数据。
- 关键字synchronized可以保证在同一时刻，只有一个线程可以执行某个方法或某个代码块，同时synchronized可以保证一个线程的变化可见（可见性），即可以代替volatile。

---
#### 实现原理
- synchronized可以保证方法或者代码块在运行时，同一时刻只有一个方法可以进入到临界区，同时它还可以保证共享变量的内存可见性

---
#### 临界区
- 交往的进程会产生错误的原因：  
  两个进程交叉访问的共享变量count或X。
- 我们把并发进程中与共享变量有关的程序段称为“**临界区**”（Critical section)。
- 一次只允许一个进程使用的资源称**临界资源**。
- 为保证临界资源的正确使用，可把临界资源的访问过程分成四个部分：  
  进入区->临界区->退出区->剩余区
- 进程中访问临界资源的那段代码称临界区。 

---
#### synchronized的三种应用方式
Java中每一个对象都可以作为锁，这是synchronized实现同步的基础：
- 普通同步方法（实例方法）
  - 锁是当前实例对象 
  - 进入同步代码前要获得当前实例的锁
- 静态同步方法
  - 锁是当前类的class对象 
  - 进入同步代码前要获得当前类对象的锁
- 同步方法块
  - 锁是括号里面的对象
  - 对给定对象加锁，进入同步代码库前要获得给定对象的锁。

---
#### synchronized的作用
- Synchronized是Java中解决并发问题的一种最常用最简单的方法 
  - 他可以确保线程互斥的访问同步代码

---
#### 举栗子
- 一.synchronized作用于实例方法
  - 多个线程访问同一个对象的同一个方法
    ```Java
    public class synchronizedTest implements Runnable {
      //共享资源
      static int i =0;
      /**
       * synchronized 修饰实例方法
      */
      public synchronized void increase(){
        i++;
      }
      @Override
      public void run(){
        for (int j =0 ; j<10000;j++){
            increase();
        }
      }

      public static void main(String[] args) throws InterruptedException {
        synchronizedTest test = new synchronizedTest();
        Thread t1 = new Thread(test);
        Thread t2 = new Thread(test);
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println(i);
      }
    }
    ``` 
    - ```Java
      public final void join()
                throws InterruptedException
      ```
      - 等待这个线程死亡。
      - 调用此方法的行为方式与调用完全相同
        - join (0)
      - 异常
        - InterruptedException 
          - 如果任何线程中断当前线程。 
          - 当抛出此异常时，当前线程的中断状态将被清除。 
    - 运行结果:20000
    - 分析：
      - 当两个线程同时对一个对象的一个方法进行操作，只有一个线程能够抢到锁。
      - 因为一个对象只有一把锁，一个线程获取了该对象的锁之后，其他线程无法获取该对象的锁，就不能访问该对象的其他synchronized实例方法，需要等到对象被释放后才能获取，但是在对象没有被释放前，其他线程可以访问非synchronized修饰的方法
  - 一个线程获取了该对象的锁之后，其他线程来访问其他synchronized实例方法现象 
    ```Java
    public class SynchronizedTest {
      public synchronized void method1() {
        System.out.println("Method 1 start");
        try {
            System.out.println("Method 1 execute");
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
          }
        System.out.println("Method 1 end");
     }

      public synchronized void method2() {
        System.out.println("Method 2 start");
        try {
            System.out.println("Method 2 execute");
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
          }
        System.out.println("Method 2 end");
      }


      public static void main(String[] args) {
        final SynchronizedTest test = new SynchronizedTest();

        new Thread(test::method1).start();

        new Thread(test::method2).start();
      }
    }
    ``` 
    - 运行结果:
      ```Java
      Method 1 start
      Method 1 execute
      Method 1 end
      Method 2 start
      Method 2 execute
      Method 2 end
      ``` 
    - 分析：
      - 可以看出其他线程来访问synchronized修饰的其他方法时需要等待线程1先把锁释放
  - 一个线程获取了该对象的锁之后，其他线程来访问其他非synchronized实例方法现象
    - 去掉上一个例子中方法二的synchronized
    ```Java
    public class SynchronizedTest {
      public synchronized void method1() {
        System.out.println("Method 1 start");
        try {
            System.out.println("Method 1 execute");
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Method 1 end");
      }

      public void method2() {
        System.out.println("Method 2 start");
        try {
            System.out.println("Method 2 execute");
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Method 2 end");
      }


      public static void main(String[] args) {
        final SynchronizedTest test = new SynchronizedTest();

        new Thread(test::method1).start();
        new Thread(test::method2).start();
      }
    }
    ```
    - 运行结果:
      ```Java
      Method 1 start
      Method 2 start
      Method 1 execute
      Method 2 execute
      Method 2 end
      Method 1 end
      ``` 
    - 分析：
      - 当线程1还在执行时，线程2也执行了
      - 所以当其他线程来访问非synchronized修饰的方法时是可以访问的
  - 当多个线程作用于不同的对象
    ```Java
    public class SynchronizedTest {
      public synchronized void method1() {
        System.out.println("Method 1 start");
        try {
            System.out.println("Method 1 execute");
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Method 1 end");
      }

      public synchronized void method2() {
        System.out.println("Method 2 start");
        try {
            System.out.println("Method 2 execute");
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Method 2 end");
      }


      public static void main(String[] args) {
        final SynchronizedTest test1 = new SynchronizedTest();
        final SynchronizedTest test2 = new SynchronizedTest();

        new Thread(test1::method1).start();

        new Thread(test2::method2).start();
      }
    }
    ``` 
    - 结果
      ```Java
      Method 1 start
      Method 1 execute
      Method 2 start
      Method 2 execute
      Method 2 end
      Method 1 end
      ``` 
      - 分析：
        - 因为两个线程作用于不同的对象，获得的是不同的锁，
        - 所以互相并不影响
      - **此处思考一个问题：为什么分布式环境下synchronized失效？如何解决这种情况？**

---
- 二.synchronized作用于静态方法
```Java
public class synchronizedTest implements Runnable {
    //共享资源
    static int i =0;
    /**
     * synchronized 修饰实例方法
     */
    public static synchronized void increase(){
        i++;
    }
    @Override
    public void run(){
        for (int j =0 ; j<10000;j++){
            increase();
        }
    }

    public static void main(String[] args) throws InterruptedException{
        Thread t1 = new Thread(new synchronizedTest());
        Thread t2 = new Thread(new synchronizedTest());
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println(i);
    }
}
```
  - 执行结果:20000
    - 分析：
      - 由例子可知，两个线程实例化两个不同的对象，但是访问的方法是静态的
      - 两个线程发生了互斥（即一个线程访问，另一个线程只能等着）
        - 因为静态方法是依附于类而不是对象的，当synchronized修饰静态方法时，锁是class对象。

---
- 三、synchronized作用于同步代码块
  - 为什么要同步代码块呢？
    - 在某些情况下，我们编写的方法体可能比较大，同时存在一些比较耗时的操作，而需要同步的代码又只有一小部分，如果直接对整个方法进行同步操作，可能会得不偿失，
    - 此时我们可以使用同步代码块的方式对需要同步的代码进行包裹，这样就无需对整个方法进行同步操作了。
  ```Java
  public class synchronizedTest implements Runnable {
    static synchronizedTest instance=new synchronizedTest();
    static int i=0;
    @Override
    public void run() {
        //省略其他耗时操作....
        //使用同步代码块对变量i进行同步操作,锁对象为instance
        synchronized(instance){
            for(int j=0;j<10000;j++){
                i++;
            }
        }
    }
    public static void main(String[] args) throws InterruptedException {
        Thread t1=new Thread(instance);
        Thread t2=new Thread(instance);
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println(i);
    }
  }
  ```
  - 运行结果:20000
  - 分析
    - 将synchronized作用于一个给定的实例对象instance，
      - 即当前实例对象就是锁对象，每次当线程进入synchronized包裹的代码块时就会要求当前线程持有instance实例对象锁，
        - 如果当前有其他线程正持有该对象锁，那么新到的线程就必须等待，这样也就保证了每次只有一个线程执行i++;操作。
        - 当然除了instance作为对象外，我们还可以使用this对象(代表当前实例)或者当前类的class对象作为锁，如下代码：
          ```Java
          //this,当前实例对象锁
          synchronized(this){
            for(int j=0;j<1000000;j++){
              i++;
            }
          }

          //class对象锁
          synchronized(AccountingSync.class){
            for(int j=0;j<1000000;j++){
              i++;
            }
          }
          ``` 

---
### wait()
- [原文链接](https://blog.csdn.net/qq_40550018/article/details/87859399)
- wait()是Object里面的方法，而不是Thread里面的，这一点很容易搞错。
  - 它的作用是将当前线程置于预执行队列，并在wait()所在的代码处停止，等待唤醒通知。
- wait()只能在同步代码块或者同步方法中执行，如果调用wait()方法，而没有持有适当的锁，就会抛出异常。
- wait()方法调用后会释放出锁，线程与其他线程竞争重新获取锁。
#### 例子
```Java
public class TestWait implements Runnable {
    private final Object object=new Object();
    @Override
    public void run() {
        synchronized (object){
            System.out.println("线程执行开始。。。");
            try {
                object.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("线程执行结束。。。");
        }
    }

    public static void main(String[] args) {
        TestWait testWait=new TestWait();
        Thread thread=new Thread(testWait);
        thread.start();
    }
}
```
- 执行结果:线程执行开始。。。
- 从结果中我们可以看出线程调用了wait()方法后一直在等待，不会继续往下执行。
  - 这也就能解释上面说的wait()一旦执行，除非接收到唤醒操作或者是异常中断，否则不会继续往下执行。

---
### notify()
- notify()方法也是要在同步代码块或者同步方法中调用的
  - 它的作用是使停止的线程继续执行
  - 调用notify()方法后，会通知那些等待当前线程对象锁的线程，并使它们重新获取该线程的对象锁，如果等待线程比较多的时候，则有线程规划器随机挑选出一个呈wait状态的线程。
- notify()调用之后不会立即释放锁，而是当执行notify()的线程执行完成，即退出同步代码块或同步方法时，才会释放对象锁。

---
#### 例子
还是上面的例子，刚才我们调用了wait()方法后，线程便一直在等待，接下来我们给线程一个唤醒的信号，代码如下：
```Java
public class TestWait implements Runnable {
    private final Object object=new Object();

    public void setFlag(boolean flag) {
        this.flag = flag;
    }

    private boolean flag=true;
    @Override
    public void run() {
        if(flag){
            this.testwait();
        }
        else {
            this.testnotify();
        }

    }
    public void testwait(){
        synchronized (object){
            try {
            System.out.println("线程开始执行。。。");
                Thread.sleep(1000);
            object.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("线程执行结束。。。");
        }
    }
    public void testnotify(){
        synchronized (object){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            object.notify();
        }
    }

    public static void main(String[] args) {
        TestWait testWait=new TestWait();
        Thread thread=new Thread(testWait);
        thread.start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        testWait.setFlag(false);
        Thread thread1=new Thread(testWait);
        thread1.start();
    }
}

```
- 运行结果
  ```Java
  线程开始执行。。。
  线程执行结束。。。
  ```
- 我们看到在调用notify()方法之后，线程又继续了。

---
### notifyAll()
- 从字面意思就可以看出notifyAll是唤醒所有等待的线程。

---
### 出现阻塞的情况
- 出现阻塞的情况大体分为如下5种:
  - 线程调用 sleep方法,主动放弃占用的处理器资源。
  - 线程调用了阻塞式IO方法,在该方法返回前,该线程被阻塞。
  - 线程试图获得一个同步监视器,但该同步监视器正被其他线程所持有。
  - 线程等待某个通知。
  - 程序调用了 suspend方法将该线程挂起。此方法容易导致死锁,尽量避免使用该方法。
- run()方法运行结束后进入销毁阶段,整个线程执行完毕。
  - 每个锁对象都有两个队列,一个是就绪队列,一个是阻塞队列。
  - 就绪队列存储了将要获得锁的线程,阻塞队列存储了被阻塞的线程。
    - 一个线程被唤醒后,才会进入就绪队列,等待CPU的调度;
    - 反之,一个线程被wait后,就会进入阻塞队列,等待下一次被唤醒。

### 断点记录
- 10.29.7:24
  - 基本完成了整体设计
  - 缺陷设计
    - 开关用了循环实现,有一定延迟
  - 下一步设计
    - 重写Basket类
      - 信号量从1个改成2个
        - 生产者消费者使用两个不同的信号量

- 10.31.22:56
  - 完成了基本设计要求
    - 有一个bug
      - 消费者线程开关无法关闭所有消费者线程
        - 原因是实现功能的监听器是采用切换开关状态来完成的
          - 但是实际上消费者这么多,很可能存在消费者从运行开始到点开关的时候都没有抢到资源使用权
      - 解决bug的方案:
        - 在主进程中设置两个计数变量用于记录当前生产/消费者线程开关该打开/关闭所有生产/消费者线程
        - 修改两个线程类的开关函数定义
          - 从原来的切换开关状态扩展到两个函数
            - 分别为至非与至是
        - 修改两个监听器的功能函数体
          - 从原来的执行开关切换函数改成根据主进程中对应计数变量确定是调用相应线程类中的置非还是置是函数

### bug&debug
#### 11.1 缓冲区空或满时通过按钮无法唤醒线程
- 原因分析:
  - 事件监听器设计时采用了for循环将开关置是置非的方式来实现线程的开关,实际上应该还需要线程的唤醒操作
- 解决方案思路流程:
  - 在循环置位后唤醒全部线程
    - (new Basket()).notifyAll()
  - 上面方案实测不可取
    - 因为锁是加在当前对象上的,new一个对象就不是原来的锁了
    - 拟定解决方案:
      ```Java
      if()
      MainFrameProducerConsumerTest.basket.notifyAll();
      ``` 