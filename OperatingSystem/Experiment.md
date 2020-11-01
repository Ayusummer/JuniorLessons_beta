# 前言
## 实验环境
- 软件:
  - VisualStudio2019Community


---
# 第1次实验 实验2 同步机构
## 数据结构
### 进程控制块结构
```C++
typedef struct Pcb {
	string name;		// 进程名
	char state;		    // 运行状态(阻塞,就绪,运行,完成)
	string wait_reason;	// 等待原因(两个信号量)
	int breakp;			// 断点
}Pcb, * Process;		// 定义struct Pcb 为 Pcb,Pcb*为Process

```
- name
  - 进程名
  - 类型设置成string是因为可能有多个进程名,用字符串比较方便管理
    - 虽然这里只有两个进程,完全可以定义为char类型,但是为了情况的普适性而选择了string
- state  
  运行状态
  - 阻塞(B)
  - 就绪(W)
  - 运行(R)
  - 完成(C)
    
- block_reason
  - 题目中程序阻塞的原因只有一个,那就是信号量与零的关系,所以可以设置成char类型
  - s表示题设中的等待信号量s的状态
  - p(positive)表示s > 0
  - n(negative)表示s < 0
  - m表示s <= 0
- breakp;			
  - 断点保护 
  - int类型

---
### 生产者进程
#### 进程

#### 结点
- P操作
  - 申请一份资源
    - 能就绪就就绪
    - 不能就绪就阻塞
  - 加入到生产者列表中
    - 这部分函数在生产者列表中定义
      - 因为无法从进程获取到进程列表
#### 列表
- 插入结点
  - 将一个生产者结点加入到列表中



---
## 随笔
### Sleep函数
- [原文链接](https://www.cnblogs.com/ruiy/p/9699819.html)
- 功 能  
  执行挂起一段时间
---
#### 用 法  
  ```C++
  unsigned sleep(unsigned seconds);
  ```
- Sleep函数的一般形式:  
  ```C++
  Sleep(unisgned long);
  ```
  - Sleep()里面的单位，是以毫秒为单位
    - 所以如果想让函数滞留1秒的话，应该是Sleep(1000);
    - 在Linux下，sleep中的“s”不大写
      - sleep()里面的单位是秒，而不是毫秒。

---
#### 示例
- 示例
  ```C++
  #include <windows.h>
  int main(){
    int a;
    a=1000;
    Sleep(a);/* VC 使用Sleep*/
    return 0;
  }
  ```
- 应用程序
  ```C++
  #include <syswait.h>
  usleep(n) //n微秒
  Sleep（n）//n毫秒
  sleep（n）//n秒
  ```
- 驱动程序
  ```C++
  #include <linux/delay.h>
  mdelay(n) //milliseconds 其实现
  #ifdef notdef
  #define mdelay(n) (\
  {unsigned long msec=(n); while (msec--) udelay(1000);})
  #else
  #define mdelay(n) (\
  (__builtin_constant_p(n) && (n)<=MAX_UDELAY_MS) ? udelay((n)*1000) : \
  ({unsigned long msec=(n); while (msec--) udelay(1000);}))
  #endif
  ```
  - 调用asm/delay.h的udelay,udelay应该是纳秒级的延时
- Dos
  ```C++
  sleep(1); //停留1秒 
  delay(100); //停留100毫秒   
  ```
- Windows: 
  ```C++
  Sleep(100); //停留100毫秒 
  ```
- Linux 
  ```C++
  sleep(1);     //停留1秒 
  usleep(1000); //停留1毫秒 
  ```
- 每一个平台不太一样,最好自己定义一套跨平台的宏进行控制 

---
#### 注意
- 头文件
  - 在VC中使用带上头文件
      ```C++
      #include <windows.h>
      ```
  - 在gcc编译器中，使用的头文件因gcc版本的不同而不同
  - linux系统需要添加的头文件　　
      ```C++
      #include <unistd.h>
      ```
  - linux下，用g++编译，得添加unistd.h头文件，gcc则加不加都可以，因为标准C中有sleep文件了。
- 书写
  - 在VC中Sleep中的第一个英文字符为大写的"S"
  - 在标准C中是sleep, 不要大写.. 
    - 下面使用大写的来说明,, 具体用什么看你用什么编译器. 
    - 简单的说VC用Sleep, 别的一律使用sleep.

---
#### 秒还是微秒？关于延时函数sleep()
- 因为要写一段代码，需要用到sleep（）函数，在我印象中，sleep(10)好像是休眠10微秒，结果却是休眠了10秒（在Linux下）。觉得很奇怪，因为头儿也记得好像是微秒为单位的。所以就查了一下。
  - 原来linux下的sleep函数原型为：
    ```C++
    unsigned int sleep(unsigned int seconds);
    ```
    - 而MFC中的Sleep函数原型为：
      ```C++
      void Sleep(DWORD dwMilliseconds);
      ```
  - 也就是说，Linux下（使用的gcc的库），sleep()函数是以秒为单位的
    - sleep(1);就是休眠1秒。
      - 而MFC下的sleep()函数是以微秒为单位的
        - sleep(1000);才是休眠1秒。
      - 原来如此啊。而如果在Linux下也用微妙为单位休眠，可以使用线程休眠函数:
        ```C++
        void usleep(unsigned long usec);
        ```
        当然，使用的时候别忘记
        ```C++
        #include <system.h>
        ```
- 另外值得一提的是，linux下还有个delay()函数，原型为
  ```C++
  extern void delay(unsigned int msec);
  ```
  它可以延时msec*4毫秒
  - 也就是如果想延时一秒钟的话，可以这么用 delay(250);

---
### C++头文件
- 头文件中定义所有的类,结构体,函数
- 与头文件对应的源文件中定义要使用的变量以及头文件中所有类,结构体,函数的主体

---
### 进程控制块
- 进程控制块（Processing Control Block），是操作系统核心中一种数据结构，主要表示进程状态。

---
#### 作用
- 其作用是使一个在多道程序环境下不能独立运行的程序（含数据），成为一个能独立运行的基本单位或与其它进程并发执行的进程。
  - 或者说，OS是根据PCB来对并发执行的进程进行控制和管理的。
-  PCB通常是系统内存占用区中的一个连续存区，它存放着操作系统用于描述进程情况及控制进程运行所需的全部信息，
- 它使一个在多道程序环境下不能独立运行的程序成为一个能独立运行的基本单位或一个能与其他进程并发执行的进程。

---
### PV操作
- PV操作是一种实现进程互斥与同步的有效方法。
- PV操作与信号量的处理相关
  - P表示通过的意思(pass)
  - V表示释放的意思
- PV操作是典型的同步机制之一。
  - 用一个信号量与一个消息联系起来，
    - 当信号量的值为0时，表示期望的消息尚未产生；
    - 当信号量的值非0时，表示期望的消息已经存在。
  - 用PV操作实现进程同步时，调用P操作测试消息是否到达，调用V操作发送消息。
- P 操作：
  - 当信号量s的整型值大于0时，它表示某类公用资源的可用数。因此，每执行一次P操作就意味着请求分配一个单位的该类资源给执行P操作的进程使用，信号量s的整型值应减去1。
  - 当信号量s的整型值小于等于0时，表示已经没有此类资源可供分配了，因此，请求资源的进程将被阻塞在相应的信号量s的等待队列中。此时，s的整型值的绝对值等于在该信号量上等待的进程数。 
- V 操作：
  - 执行一次V操作就意味着进程释放出一个单位的该类可用资源，故信号量s的整型值应增加1。
  - 若s的整型值还小于等于0，表示在信号量s的等待队列中有因请求该类资源而被阻塞的进程，因此，就把等待队列中的一个进程唤醒，使之转移到就绪队列中去。
  - **注意：唤醒的次序依系统而定。** 

---
### 结构体与结构体指针
- 结构体指针可用于在结构体数组间移动
  - 单个进程与进程数组的定义

---
### C++预定义
```C++
#define volume_buffer 10;	// 根据题设,缓冲区容量为10
```

---
### C++整型数据转字符串
```C++
// 将int 转换成string
string itos(int i){
	stringstream s;
	s << i;
	return s.str();
}
```

---
### C++内存的申请与释放
```C++
no malloc no free
no new no delete
```