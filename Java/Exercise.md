# 前言
- 笔记中涉及的Java规约大多是阿里巴巴Java开发手册(嵩山版)中的规约
  - 以下简称(**嵩山版规约**)

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


### 断点记录
- 10.29.7:24
  - 基本完成了整体设计
  - 缺陷设计
    - 开关用了循环实现,有一定延迟
  - 下一步设计
    - 重写Basket类
      - 信号量从1个改成2个
        - 生产者消费者使用两个不同的信号量