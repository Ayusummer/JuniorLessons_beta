# 微机原理,汇编语言与接口技术
# 前言
## 教师信息
- 主讲：刘芳
- 办公室：计算机楼528
- 学习QQ交流群：981831953
- 集中线下答疑时间：周三下午两点后

---
## 本次课程主要内容
### 课程介绍
- 微型计算机的发展及应用
- 微型计算机系统的组成
- 计算机中数据的表示（自行复习掌握）
- 计算机中的常用逻辑部件（自行复习掌握）

---
### 教学目的
#### 硬件系列课程之一
- 计算机组成原理
	- 对计算机系统的基本组成和工作机制有了比较透彻的理解
	- 微机原理与系统
	- 计算机体系结构
		- 重点论述计算机系统的各种基本结构，设计技术和性能定量分析方法 

---
#### 本课程的目的
- 进一步理解微处理器的内部结构和工作原理
- 理解微型计算机系统的组成和工作原理
- 理解常用接口芯片的使用方法
- 具有微机系统软硬件开发的初步能力 

---
## 教学内容
- 总学时：56+16. 学分：4
	- 第1章 微型计算机系统概述	->2
	- 第2章 汇编语言基础->16
	- 第3章 汇编语言程序俄设计->7
	- 第4章 16位微处理器的外部特性->3
	- 第6章 微型计算机输入和输出技术	->5
	- 第7章 微型计算机的中断系统->5
	- 第8章 可编程接口芯片->12
	- 第10章 模数和数模转换技术->6 

---
## 课程考核
笔试：50%
- 实验：20%（地点：计算机楼）
	- 8次实验（3次软件，5次硬件机房）16课时
	- 请各位班长区实验室办公室（计311）安排时间
	- 可以顺便咨询一下排课算法
- 平时：30%，包括：
	- 作业：主要考察是否认真学习，以及独立思考，独立理解的能力，**杜绝作业抄袭！**
	- 课堂听讲  

---
## 微型计算机系统组成
---
### 冯·诺依曼思想
- **存储程序，程序控制**，计算机五大功能部件
- ![此处应有五大部件结构图](ss)

---
### 微型计算机
- **以微处理器为核心**，配上由大规模集成电路制作的只读存储器（ROM），读写存储器（RAM），输入/输出接口电路以及相应的辅助电路等所组成的计算机，称为**微型计算机[Microcomputer]**
- 将这些组成部分基层在一片超大规模集成电路芯片上，称为单片微型计算机，建成**单片机**。
  - 单片机体积小，功耗低，在智能化仪器仪表以及控制领域应用极广。
- 以微型计算机为中心，配以相应的外围设备（如键盘。鼠标，显示器，打印机等）和其他专用电器，电源，面板，
【没打完】

![Alt](https://i.loli.net/2020/09/07/vmho5OJIracRH6M.jpg)
![Alt](https://i.loli.net/2020/09/07/E9ADdnaLHUslxmj.jpg)

---
## 系统总线
- **总线**是计算机的部件与部件之间传输信息的**公共通路**，
- 【没打完】
- ![alt](https://i.loli.net/2020/09/07/K1xzr6lUsT5Zg3a.jpg)
  - ![Alt](https://i.loli.net/2020/09/07/k5KQiLnBPXvUlsq.jpg)
- 总线使用特点
  - 在某一时刻，只能**由一个总线主控设备**(例如CPU)来控制总线
  - 在连接重点的各个设备中，某时刻只能有一个**发送者** 向总线 **发送信号**；但是可以有**多个设备**从总线上同时**获取信号**  
  - 微机系统采用**“总线结构”**，具有组态灵活，扩展方便的优势

---
## 总线与三态
【没抄完】

## 微机系统主要性能指标
![Alt](https://i.loli.net/2020/09/07/mhj3rFGC6DkxPIU.jpg)

## 计算机内数据的表示
![Alt](https://i.loli.net/2020/09/07/QSzXv8VOyM1nEYg.jpg)![Alt](https://i.loli.net/2020/09/07/WMXHxsRJfSk8VZv.jpg)![Alt](https://i.loli.net/2020/09/07/iPlpnuXk13yfSZQ.jpg)

# 第1章 微型计算机系统概述

## 历史背景
- 机械时代
	- 算盘
- 电子时代
	- 第一台数字电子计算机ENIAC，1946年2月于美国宾夕法尼亚大学研制成功；
		- 开关定位，线路连接变成
			- 容易损坏 
		- 十进制
		- 冯·诺依曼计算机的特点：
			- 数据存储
			- 5大部件：控制器，·，存储器，输入设备，输出设备 
- 电子计算机的发展
	- 电子管计算机（Vacuum Tubes）
	- 晶体管计算机（Transistors）
	- 中小规模集成电路计算机
	- **大规模/超大规模集成电路计算机** 
		- 这之后才出现了微型计算机 
		- 集成度->摩尔很著名（提出了什么理论）
			- 查一下
	- 电子计算机按其性能和规模分类
		- 大型计算机
		- 中性计算机
		- 小型计算机
		-   **微型计算机**
			- 我们重点来看微型计算机的特征
				- 大规模/超大规模集成电路为核心  
		- 单片计算机

## 霍夫和Intel 4004
- **1971年**1月，Intel公司的**霍夫**等人成功研制出世界上第一块4位微处理器芯片Intel 4004 ，标志着第一代微处理器问世，微处理器和危机时代从此开始；
- 1971年11月，Intel推出MCS-4微型计算机系统，其包括4001 POM芯片，4002 RAM芯片，4003移位寄存器芯片和4004位处理器
- ![Alt](https://i.loli.net/2020/09/07/oU1ufIWsVqdYJ3D.jpg)
	- 80486还是32位
	- 我们课程要学习的是8086
		- 1978年推出的
		- 非常典型，适合入门学习 
- ![Alt](https://i.loli.net/2020/09/07/uSnI192gRhrOj6d.jpg) 
	- 到奔腾系列已经都是64位处理器了

## 微处理器家族的兼容性（compatibility）
- 向上兼容
	- 在多机种同时存在的情况下，为某个单词集中编制的软件能够不加修改地运行在比他高档的机种上

- 向后兼容
  - 为某个时期生产的集中编制的软件能够不加修改地运行在他之后新生产的机种上

## 微型计算机的发展
- 分代标志：**字长和典型微处理器**
- ![Alt](https://i.loli.net/2020/09/07/3t1S9gqkvTV6fCs.jpg)
	- 8086时已经有了流水线技术，加上市场的需求，所以生产了比前代性能要低的8086

## 微型计算机的应用
- 应用领域
  - 科学计算，数据处理，实时控制，计算机辅助设计，人工智能，...
- 应用方向
  - 数值计算，数据处理及信息管理
    -  通用微机（如PC）
    - 功能越强越好，使用越方便越好   
  - 过程控制及嵌入应用方向
    - 专用微机，例如：工程机，单片机
    -  可靠性高，实时性强
    - 程序相对简单，处理数据量小

---
# 第2章 汇编语言基础
## 汇编语言开发过程

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_4f24a32d86e3b8a797a7220fd0bef14c.png)

### 第1步:编辑

- **源程序文件要以asm为扩展名**
- 源程序文件的编辑任选一个文本编辑器即可
- DOS中的全屏幕文本编辑器EDIT
  - EDIT ex201.asm
- 其他程序开发工具中的编辑环境(记事本或者写字板)

### 第2步:源程序的汇编

- 汇编是将源程序翻译成由机器代码组成的目标模块文件的过程
  - MASM ex201.asm 或 MASM ex201	; 后缀可以省略
  - 如果源程序中没有语法错误,MASM将自动生成一个目标模块文件(*.obj);否则MASM将给出相应的错误信息
    - 这时根据错误信息,重新编辑修改源程序后再进行汇编

---
## 2.5 汇编语言中的操作数
![8086Structure](R/../res/8086Structure.png)
![PSW](R./../res/PSW.png)
> PF(Parity Flag)奇偶标志
> TF(Trap Flag)陷阱标志

### 2.5.1 常量
- 常量表示一个固定的数值,它又分为多种形式
  - 常数
  - 字符串
  - 符号常量
  - 数值表达式

---
#### 常数
- 指由10、16、2和8进制形式表达的数值，各种进制的数据以后缀字母区分，默认不加后缀字母的是十进制数  

| 十进制 | 十六进制 | 二进制 |
| -------- | -------- | -------- |
| 由0 ~ 9数字组成，以字母D（d）结尾（缺省情况可以省略） | 由0 ~ 9、A ~ F数字组成，以字母H （h）结尾，以字母开头的常数需要加一个前导0 | 由0和1两个数字组成，以字母B（b）结尾  |
| 100，255D | 64H，0FFH，0B800H | 01100100B |

---
#### 字符串
- 字符串常量是用**单引号**或**双引号**括起来的单个字符或多个字符
- 其数值是每个字符对应的ASCII码值
- 例如
  - ‘d’（等于64H）
  - ‘AB’（等于4142H）
  - ‘Hello, Assembly !’

---
#### 符号常量
- 符号常量使用标识符表达一个数值
- 符号常量定义伪指令有“**EQU**”和“**＝**”两种：
  - 符号名 EQU 数值表达式
  - 符号名 ＝ 数值表达式
- EQU用于数值等价时**不能重复定义**符号名，但“＝”允许有重复赋值。  
  例如：
  - X= 7    ；等效于：X equ 7
  - X= X+5  ；“X EQU X+5”是错误的
- 汇编时，对EQU定义的符号名用对应的表达式进行“**替换**”。
  例如：
  ```
  NUM EQU 215 MOD 15
  ERR_MSG EQU “Data Override ”
  ```
  ```
  MESSAGE DB ERR_MSG
  ；等价于MESSAGE DB “Data Override ”
  MOV CX, NUM+1
  ；等价于MOV CX, 215 MOD 15+1
  ```

---
#### 数值表达式
- 数值表达式一般是指由**运算符**连接的**各种常量**所构成的表达式
- 汇编程序**在汇编过程中计算表达式**，最终得到一个确定的数值，所以也是常量
- 表达式的数值在程序运行前的汇编阶段计算，所以**组成表达式的各部分必须在汇编时就能确定**
- 汇编语言支持多种运算符
  - 例如:
    ```
    mov ax,3*4+5 ；等价于：mov ax,17
    ```
- 构成数值表达式可使用以下几类运算符：
  - 算术运算符   
    (+，-，*，/，mod)
  - 逻辑运算符  
    (shl, shr, and, or, xor, not)
  - 关系运算符  
    (gt, ge, eq, le, lt, ne) 
  - 地址运算符
    (seg, offset)
  - 类型运算符
    (type, length, size)


### 2.5.2 变量和符号

1. 变量的定义
2. 

3. 变量的应用

   - 变量应用举例:

   - ;代码段  
<code>
     MOV CL，BVAR             ;BVAR第1个数据送CL，（CL）=01H 

     MOV CH，BVAR+2						;BVAR第3个数据送CH，（CH）=41H 

     MOV BX，WVAR							;VAR第1个数据送BX，（BX）=0001H 

     MOV SI，WVAR+2						;WVAR第2个数据送SI，（SI）=0FFFEH（-2）

     MOV DX, WORD PTR DVAR		;DVAR第1个数据低字送DX，（DX）=0001H 

     MOV AX, WORD PTR DVAR+2	;DVAR第1个数据高字送AX，（AX）=0000H
     MOV DI, VAR1+4 					;VAR1第3个数据送WVAR第7个数据单元。

     MOV WVAR+12, DI
</code>

1. 变量的定位
- 汇编程序按照指令的先后顺序一个接着一个分配存储空间，按照段定义伪指令规定的边界定位属性确定每个逻辑段的起始位置（包括偏移地址）
- 定位伪指令ORG控制数据或代码所在的偏移地址:
  - ORG 参数
- ORG伪指令是将当前偏移地址指针指向参数表达的偏移地址。例如：
  - ORG 100h ；从100H处安排数据或程序
  - ORG $+10 ；偏移地址加10，即跳过10个字节空间 
- 汇编语言程序中，符号“$”表示当前偏移地址值
- ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_4eabbb43b589f66592807ea60f0183e3.png)
## **本次课学习要求**
- 掌握：
- [ ] 数据的定义
- [ ] 常量
  - EQU
  -  数值表达式各部分必须在汇编时能够确定
- [ ] 变量的定义与使用
  - DB、DW、DD
  - DUP
  - OFFSET、SEG、PTR、ORG、’$'

---
## 2.6 8086/8088 的寻址方式
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_18e528808f7549b45d74808a87623094.png)
1. 指令的组成
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_b11987890e3e03b7687aa01c357b39ad.png)
- **操作码**说明计算机要执行的**操作**，如传送、运算、移位等操作，它是指令中不可缺少的组成部分。
  - 用一个助记符表示（指令功能的英文缩写）
  - 对应着机器指令的一个或多个二进制编码
- **操作数**是指在指令执行过程中需要处理的**对象**
  - 有些指令不需要操作数，通常的指令都有一个或两个操作数，也有个别指令有3个甚至4个操作数 
  - 可以是一个具体的数值
  - 可以是存放数据的寄存器
  - 或指明数据在主存位置的相关信息
  
**指令的助记符格式**
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_26ce59eb356f84ed4cfbaa34782da913.png)
- 操作数2，源操作数 SRC，
  - 参与指令操作的一个对象
- 操作数1，目的操作数 DST，
  - 参与指令操作的另一个对象；
  - 同时也用来存放指令操作的结果
- 分号后的内容是对指令的解释
---
2. 8086的寻址方式
- 与数据有关的寻址方式：以 MOV 指令为例
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_d29b94a76a612071151f60d2065a4bee.png)

![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_0f031aa10ba6dd82c76142d3df522238.png)

### 2.6.1 立即寻址 —— 操作数在指令中给出
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_b4dc0af73fdf80d1c900f55383014340.png)
- 只能用于 SRC 字段  MOV 40H, AL  (×)
- SRC 和 DST 的字长一致 MOV AH, 3064H (×)
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_e52261c6a2162083528b6c705f5ba0cd.png)

### 2.6.2 寄存器寻址方式 — 操作数在指定的寄存器中
- 指令格式:  
  MOV AX, BX  
  MOV AL, BH  
  MOV AX, 3064H
- 字节寄存器只有 AH AL BH BL CH CL DH DL
- SRC 和 DST 的字长一致 MOV AH, BX (×)
- CS 不能用 MOV 指令改变 MOV CS, AX (×)

### 2.6.3 直接寻址方式 — 有效地址EA由指令直接给出
- 例:  
  MOV AX, [0300H ]  
  EA=0300H, 假设(DS)=0AE8H, 那么PA=0B180H
- 隐含的段为数据段 DS
- 可使用**段超越前缀**:MOV AX, ES: [2000H]
- 操作数地址可由变量（符号地址）表示, 但要注意变量的属性:  
  VALUE DB 10  
  MOV AH, VALUE  
  MOV AX, VALUE (×)
  MOV AX, WORD PTR VALUE (√)  
  ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_45ae4bac19c9495ecde745800cc16b07.png)

### 2.6.4 寄存器间接寻址

### 2.6.5 寄存器相对寻址方式

### 2.6.6 基址变址寻址

### 2.6.7 相对基址变址寻址


## 2.7 8086/8088指令系统 
### 重点关注：
- 指令的汇编格式
- 指令的基本功能
- 指令支持的寻址方式
- 指令的执行对标志位的影响
- 指令的特殊要求

### 2.7.1 数据传送类指令
- 通用数据传送指令
  - MOV、PUSH、POP、XCHG
- 累加器专用传送指令
  - IN、OUT、XLAT
- 地址传送指令
  - LEA、LDS、LES
    - LEA和OFFSET操作符都可以取到有效地址,但是注意不要把二者搞混了 
- 标志寄存器传送指令
  - LAHF、SAHF、PUSHF、POPF
- 符号扩展指令
  - CBW、CWD
#### 通用数据传送指令    
- 通用传送指令包括
  - 基本传送指令:MOV
  - 堆栈指令PUSH和POP
  - 交换指令XCHG
##### 基本传送指令MOV,
- 传送指令： MOV DST, SRC
- 执行操作： (DST) <- (SRC)
- 注意:
  - DST、SRC必须有**相同的类型**，可以同是字节或字等 
  - DST、SRC **不能同时为段寄存器**
    - 硬件不支持 
    - MOV DS, ES (×)
  - **立即数不能直接送段寄存器**
    - MOV DS, 2000H (×)
  - DST 不能是立即数和CS
  - DST、SRC **不能同时为存储器寻址**
  - 不影响标志位
  - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_01c8b5c575a97ab26fe6ba01f39225ef.png)
- MOV指令正确的数据传送方向
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_8bfe61b2fd875f673c1b2e467a7d92b3.png)   
  - IP和PSW不可以寄存器寻址,二者都是控制寄存器

- 【例 2-7】数据传送
  - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_31d270828e91a5413fc01af52d464a5a.png)

- 【例 2-8】 将存储单元3000H的一个字的内容送至4000H单元  
  - 指令  
   MOV AX,[3000H]     
   MOV [4000H],AX  
  - 也可以通过其它通用寄存器传送，但不能直接在两个存储单元间传送

- 【例 2-9】 判断指令对错，并指出错误原因。
  - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_d1d9e0ff6f504a2fcc9922c667cab74b.png)
  
##### 堆栈操作指令PUSH和POP
- 堆栈操作指令有两条(用于完成入栈和出栈操作)
  - 入栈指令PUSH
  - 出栈指令POP
- 堆栈：‘先进后出’的存储区，段地址存放在SS中，SP在任何时候都指向栈顶，进出栈后自动修改SP。
- 注意:
  - 堆栈操作**必须以字为单位** 
  - 不影响标志位
  - **不能用立即寻址方式** 
    - PUSH 1234H (×)
  - **DST不能是CS** 
      - POP CS (×)
- 堆栈段的特点：
  - 从较大地址开始分配和使用（数据段、代码段从较小地址开始分配和使用）； 
  - SP指向的存储单元称为“栈顶”，堆栈操作时，数据总是在“栈顶” 位置存入（ “压入”）、取出（ “弹出”）；
  - 最先进入的数据最后被弹出，最后进入的数据最先被弹出
    - 例：堆栈段的定义：
      - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_b513d0643100f4ffdbc304ad59d3df35.png)  
      - 该程序装入时，操作系统把SSEG的**段基址置入SS**，堆栈段的**字节数置入SP** ，即200（ 0C8H）
  - 如果未定义堆栈段，**用户程序装入内存时：**
    - ES, DS指向PSP;
    - SS指向用户程序区；
    - CS指向用户代码段(由END伪指令指明）；
    - (SP)=0000H, 指向64KB存储器尾部  
    - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_8d762d2a1829aeb4d066f370242fac55.png)

##### 交换指令XCHG
- 利用交换指令可方便地实现通用寄存器与通用寄存器或存储单元见的数据交换

#### 累加器专用传送指令

##### 字节转换指令XLAT(也称换码指令或查表指令)

#### 地址传送指令

### 2.7.2 算数运算类指令
- 加法指令  
  ADD、ADC、INC
- 减法指令  
  SUB、SBB、DEC、NEG、CMP
- 乘法指令  
  MUL、IMUL
- 除法指令  
  DIV、IDIV
- 十进制调整指令  
  DAA、DAS、  
  AAA、AAS、AAM、AAD
#### 加法指令
- 加法指令： ADD DST, SRC
- 执行操作： (DST) <- (SRC) + (DST)
---
- 带进位加法指令： ADC DST, SRC
- 执行操作： (DST) <- (SRC) + (DST) + CF
---
- 加1指令： INC OPR
- 执行操作： (OPR) <- (OPR) + 1
---
- 注意:**都影响状态标志位，但 INC指令不影响CF标志位**

#### 减法指令
- 减法指令： SUB DST, SRC
- 执行操作： (DST) <- (DST) - (SRC)
---
- 带借位减法指令： SBB DST, SRC
- 执行操作： (DST) <- (DST) - (SRC) - CF
---
- 减1指令： DEC OPR
- 执行操作： (OPR) <- (OPR) - 1
---
- 求补指令： NEG OPR
- 执行操作： (OPR) <- - (OPR)
---
- 比较指令： CMP OPR1, OPR2
- 执行操作： (OPR1) - (OPR2)
---
- **注意**:除DEC指令不影响CF标志(进位标志)外，均对状态标志位有影响
---
- 【例 2-17】 试分析如下指令执行结果及标志位的状态  
```
MOV BX,0 ; (BX)=0，不影响标志位
DEC BX 
; (BX)=0FFFFH，CF不影响、PF=1、AF=1、ZF=0、SF=1、OF=0
INC BX ; (BX)=0，CF不影响、PF=1、AF=1、ZF=1、SF=0、OF=0
SUB BX,1
; (BX)=0FFFFH，CF=1、PF=1、AF=1、ZF=0、SF=1、OF=0
NEG BX ; (BX)=1，CF=1、PF=0、AF=1、ZF=0、SF=0、OF=0
```

#### 乘法指令
- 无符号数乘法指令： MUL SRC
- 带符号数乘法指令： IMUL SRC
- 执行操作：
  - 字节操作数 (AX) <- (AL) * (SRC) 
  - 字操作数 (DX, AX) <- (AX) * (SRC)
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_9707a2f4b3111c4776e195333f64030a.png)
- 注意:
  - **AL (AX) 为隐含的乘数。 AX (DX,AX) 为隐含的乘积。**
  - **src若为存储器操作数时，注意用ptr明确类型。**  
    如：MUL WORD PTR [BP][DI] ; 字乘，乘积送DX:AX
  - **SRC不能为立即数和段寄存器**
---
- 除CF和OF外，对其它状态标志位无定义 
- 乘法指令对 CF/OF 的影响：
  - MUL指令: CF,OF =
    - 00 乘积的高一半为零
    - 11 否则
  - IMUL指令: CF,OF =
    - 00 乘积的高一半是低一半的符号扩展
    - 11 否则
---
- 例 2-19 ： 已知（AL）=0FFH，（BL）=2，
```
MUL BL ;乘积(AX)= 01FEH,(255×2 = 510), CF=OF=1
IMUL BL ;乘积(AX)= 0FFFEH,(-1×2 = -2), CF=OF=0
```
- 对标志没有定义：指令执行后这些标志是任意的、不可预测（就是不知道是0还是1）
- 对标志没有影响：指令执行不改变标志状态
---
#### 除法指令
- 无符号数除法指令： DIV SRC
- 带符号数除法指令： IDIV SRC
- 执行操作：
  - 字节操作
    - (AL) <- (AX) / (SRC) 的商  
    - (AH) <- (AX) / (SRC) 的余数
  - 字操作
    - (AX) <- (DX, AX) / (SRC) 的商  
    - (DX) <- (DX, AX) / (SRC) 的余数
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_bdce583dfeb751dd43435597b36c757d.png)
- **注意:**
  - AX (DX,AX) 为隐含的被除数寄存器。
  - AL (AX) 为隐含的商寄存器
  - AH (DX) 为隐含的余数寄存器
  - **SRC不能为立即数**
  - **对所有状态标志位均无定义。**
  - **两个N位操作数相除，应首先把被除数符号扩展为2N位。**
  - src若为存储器操作数时，注意用ptr明确类型。 
    - 如：IDIV BYTE PTR [DI] ;AX除以8 位存储器操作数 
---
- 例 2-20：已知（AX）=0410H，（BL）= 0B8H。
```
DIV BL ;商AL=05H ，余数AH=78H
IDIV BL ;商AL=F2H(即－14)，余数AH=20H(即32)
;有符号数0410H真值为1040，B8H 真值为－72。 ;注意DIV和I DIV的区别
```
---
#### 表达式计算
- 【例 2-21】X、Y、Z、V、W均为16位有符号数，计算W←(V-(X*Y+Z-1234))/X
##### 确定计算顺序如下：
1. X*Y → 暂存中间结果。
2. X\*Y+Z → X*Y+Z-1234 → 暂存中间结果。
3. V-(X\*Y+Z-1234) → (V-(X*Y+Z-1234))/X → 保存最终结果。
##### 确定各次运算的数据类型：
1. X*Y 乘积为32位。
2. X\*Y结果为32位，Z进行符号扩展成32位， X*Y+Z-1234 结果为32位。
3. X\*Y+Z-1234的结果是32位，V需扩展到32位，(V-(X\*Y+Z-1234))结果为32位，X为16位，因此，(V-(X*Y+Z-1234))/X最终结果为16位。
```
MOV AX, X 
IMUL Y ; X*Y
MOV CX, AX ; X*Y(32位)暂存入BX:CX。DX:AX需用于Z的符号扩展
MOV BX, DX
MOV AX, Z ; Z置入AX进行符号扩展至DX:AX，扩展为32位
CWD
ADD CX, AX
ADC BX, DX ; X*Y+Z
SUB CX, 1234 
SBB BX, 0 ; X*Y+Z-1234
MOV AX, V ; V置入AX进行符号扩展至DX:AX，扩展为32位
CWD
SUB AX, CX
SBB DX, BX ; V-(X*Y+Z-1234)
IDIV X ; (V-(X*Y+Z-1234))/X，商在AX中，余数在DX中。
MOV W, AX ; 保存最终结果
```
---
#### 小结
- 加法指令  
  ADD、ADC、INCo
- 减法指令  
  SUB、SBB、DEC、NEG、CMP
- 乘法指令  
  MUL、IMUL
- 除法指令  
  DIV、IDIV
- 表达式计算
- ---

### 2.7.3 逻辑运算类指令
- 逻辑运算指令  
  AND、OR、NOT、XOR、TEST
- 移位指令  
  SHL、SHR、SAL、SAR、ROL、ROR、RCL、RCR

#### 逻辑运算指令
- 逻辑非指令：NOT OPR
  - **OPR不能为立即数**
  - 执行操作： (OPR)<- $\neg(OPR)$
  - **不影响标志位**
- 逻辑与指令：AND DST, SRC
  - 执行操作： (DST) <-(DST) $\wedge$ (SRC)   
- 逻辑或指令：OR DST, SRC
  - 执行操作： (DST) <- (DST) $\vee$ (SRC) 
- 异或指令： XOR DST, SRC
  - 执行操作： (DST) <- (DST) $\forall$ (SRC)
- 测试指令： TEST OPR1, OPR2  
  - 执行操作： (OPR1) $\wedge$ (OPR2)   

| CF | OF | SF | ZF | PF | AF    |
| -- | -- | -- | -- | -- | ----- |
| 0  |  0 | *  | *  | *  | 无定义|


#### 移位指令
##### 逻辑左移 SHL OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_aa2b4439d0be890688f80b159a73047c.png)

---
##### 逻辑右移 SHR OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_4f0534a778b95db7d9390e48b84959e6.png)

---
##### 算术左移 SAL OPR, CNT（同逻辑左移）
---
##### 算术右移 SAR OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_ad5288d06d518f8e0b456483071a5efc.png)

---
##### 循环左移 ROL OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_8d198335cd4f3701a0f273e4a0b37649.png)

---
##### 循环右移 ROR OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_3aeba43a66c5d8f0d2b9b4ec9aa518c4.png)

---
##### 带进位循环左移 RCL OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_f0f0c78a2ecb9ca925d127de42eba474.png)

---
##### 带进位循环右移 RCR OPR, CNT
![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_ec66e7291118954c13637538a73efd21.png)

---
##### **注意**
- OPR可用除立即数以外的任何寻址方式
- CNT=1，SHL OPR, 1  
  CNT>1，MOV CL, CNT  
  $\qquad$SHL OPR, CL ; 以SH  L为例
- 状态标志位：
  - CF = 移出的数值
  - OF=
    - 1 CNT=1时，最高有效位的值发生变化
    - 0 CNT=1时，最高有效位的值不变
    - **当移位次数大于1时，OF不确定**
- 移位指令： SF、ZF、PF 根据移位结果设置，AF无定义
- **循环移位指令： 不影响 SF、ZF、PF、AF**

> 逻辑左移一位相当于无符号数乘以2  
> 逻辑右移一位相当于无符号数除以2  
> 算术左移一位相当于有符号数乘以2  
> 算术右移一位相当于有符号数除以2  

---
## 2.8 转移控制类指令与分支程序设计
### 程序结构
- 顺序结构
- 循环结构
- 分支结构
- 子程序结构
> 控制转移类指令通过改变IP（和CS）值，实现程序执行顺序的改变

---
### 与转移地址有关的寻址方式  
用来确定转移控制类指令的转向地址（目标地址）。
- 直接寻址方式(用标号表达)   
  - 指令代码中直接给出地址差（即目的地址**相对**于当前IP的位移量），转移到的目的地址（转移后的IP值）就是当前IP值加上位移量 
- 间接寻址方式(用寄存器或存储器操作数表达)
  - 指令代码中指示寄存器或存储单元，目的地址从寄存器或存储单元中**间接**获得 

---
### 目标地址的寻址范围：段内寻址
- 段内转移--近转移（near）
  - 在当前代码段64KB范围内转移（±32KB范围） 
  - 不需要更改CS段地址，**只要改变IP偏移地址**
- 段内转移——短转移（short）
  - 转移范围可以用一个字节表达，在段内－128～＋127范围的转移 

---
### 目标地址的寻址范围：段间寻址
- 段间转移——远转移（far）
  - 从当前代码段跳转到另一个代码段，可以在1MB范围 
  - 需要更**改CS段地址和IP偏移地址**
  - 目标地址必须用一个32位数表达，叫做32位远指针，它就是逻辑地址
  - > 实际编程时，汇编程序会根据目标地址的 段属性，**自动处理**成短转移、近转移或远转移
  - > 程序员可用操作符short、near ptr 或far ptr 强制成为需要的转移类型

---
### 控制转移指令
- 无条件转移指令  
  JMP
- 条件转移指令  
  JZ / JNZ 、 JE / JNE、 JS / JNS、 JO / JNO、JP / JNP、 JB / JNB、 JL / JNL、 JBE / JNBE、JLE / JNLE、 JCXZ
- 循环指令  
  LOOP、LOOPZ / LOOPE、LOOPNZ / LOOPNE
> 8086系统中条件转移类指令和循环指令都只支持段内短转移
- 子程序调用和返回指令  
  CALL、RET
- 中断与中断返回指令  
  INT、INTO、IRET
> 之前学习的指令还会注意指令对标志位的影响  
> 这里还要看这些指令是如何修改CS:IP的值的

- 2-21 设
  ```
  (CS) = 3000H,
  (DS) = 2000H,
  (BX) = 0030H,
  (SI) = 0202H,
  (20232H) = 00H,
  (20233H) = 06H,
  ```
  分别执行下述两条指令后,实际转移的目标地址物理地址多少?
  - JMP BX
    - 相当于 IP<-BX 
      - > 注意IP不能作为MOV指令的操作数 
    - 目标物理地址是30030H
    - > CS的3和IP的0030H
  - JMP Word PTR[BX+SI]
    - 相当于 IP<-Word PTR[BX+SI]
    - 存储器寻址方式里的基址变址寻址
    - > 除了逻辑地址计算是在20位地址加法器里计算的,其他都是在ALU里计算的
    - > 有效地址的计算在ALU中计算,只能留16位
    - BX+SI=0232H 
    - 默认采用DS所以就是20232H取一个Word,即为0600H
    - 30600H
      - > CS的3和IP的0600H 

---
### 无条件转移指令
```
JMP OPR ；程序转向OPR指定的地址
```
- 只要执行JMP指令，就使程序转到指定的目标地址处，从目标地址处开始执行那里的指令
- 操作数OPR是要转移到的**目标地址**
- JMP指令分成4种类型
  - 段内转移、直接寻址
  - 段内转移、间接寻址
  - 段间转移、直接寻址
  - 段间转移、间接寻址

---
#### jmp 示例
```
        jmp again      ；转移到again处继续执行
        ……
again:  dec cx         ；标号again的指令
        ……
        jmp output     ；转向output
        ……
output: mov result,al  ；标号output的指令
```

---
### 条件转移指令  
条件转移指令Jcc根据指定的条件确定程序是否发生转移
```
Jcc label ；条件满足,发生转移
          ；IP←IP＋8位位移量；
          ；否则，顺序执行
```
- label是一个标号、一个8位位移量
- Jcc**只支持短转移**

---
#### Jcc指令的分类
- Jcc指令不影响标志位，但要利用标志位
- 根据利用的标志位不同，分成4种情况：
  - 判断单个标志位状态
  - 比较无符号数高低
  - 比较有符号数大小
  - 测试 CX 的值为 0 则转移
- > Jcc指令实际虽然只有16条，但却有30个助记符
- > 采用多个助记符，目的是为了方便记忆和使用

#### 根据单个条件标志的设置情况转移
| 格式 | 测试条件 |
| ---- |---- |
| JZ(JE) OPR | ；ZF = 1 |


#### 例
设字符的ASCII码在AL寄存器中,将字符加上奇校验位;(字符ASCII码中"1"的个数已为奇数时,则令其最高位为"0";否则令最高位为"1")
```
      and al,fh   ;最高位置"0",同时判断"1"的个数
      jnp next    ;个数已为奇数,则转向next
      or al,80h   ;否则,最高位为"1"
next: ...
```

---
# 第3章 汇编语言程序设计

---
## 3.2分支程序设计
- 根据条件是真或假决定执行与否
  - 判断的条件：各种指令(如CMP、TEST等)执行后形成的状态标志
- 分支控制  
  转移指令Jcc和JMP可以实现
- 分支结构有
  - 单分支结
  - 双分支结构
  - 多分支结构

### 3.2.1 单分支结构
- 条件成立跳转，否则顺序执行分支语句体
- 注意选择正确的条件转移指令和转移目标地址

---
#### 例:计算AL中有符号数的绝对值
```
        cmp al,0
        jge nonneg ；条件满足（AL≥0），转移
        neg al ；条件不满足，求补
nonneg: mov result,al ；条件满足
```
```
        ；不恰当的分支
        cmp al,0
        jl yesneg ；条件满足（AL＜0），转移
        jmp nonneg
yesneg: neg al ；条件满足，求补
nonneg: mov result,al ；条件不满足
```

---
### 3.2.2 双分支结构
- 条件成立跳转执行第2个分支语句体，否则顺序执行第1个分支语句体
- 注意第1个分支体后一定要有一个**JMP指令**跳到第2个分支体后

---
#### 【例 3-3】显示BX的最高位
```
      shl bx,1    ；BX最高位移入CF标志
      jc one      ；CF＝1，即最高位为1，转移
      mov dl,30h  ；CF＝0，即最高位为0：DL←30H＝‘0’
      jmp two     ；一定要跳过另一个分支体
one:  mov dl,31h  ；DL← 31H＝‘1’
two:  mov ah,2
      int 21h     ；显示
```

```
;显示BX的最高位（另解1）
      shl bx,1    ；BX最高位移入CF标志
      jnc one     ；CF＝0，即最高位为0，转移
      mov dl,31h  ；CF＝1，即最高位为1：DL←31H＝‘1’
      jmp two     ；一定要跳过另一个分支体
one:  mov dl,30h  ；DL← 30H＝‘0’
two:  mov ah,2
      int 21h     ；显示
```


---
#### 2-22
编写指令序列,实现下述要求:
- 测试BX中的位0和位4,当这两位同时为零时,将AL各位置1,否则AL各位置0;
```
      TEST BX,0011H
      JZ NEXT
      XOR AL,AL     ;AL清0
      JMP OVER
NEXT: MOV AL,0FFH   ;AL置1
OVER: ......
```


---
## 3.3 循环程序设计
- 3.3.1 计数循环
- 3.3.2 条件循环
- 3.3.3 多重循环

---
### 1. 循环指令
- 注意：
  - CX 中存放循环次数
  - 只能使用段内直接寻址的8 位位移量  
    ```
    LOOP
    LOOPZ / LOOPE
    LOOPNZ / LOOPNE
    ```
- 执行步骤：
  - (1) (CX) ← (CX) - 1
  - (2) 检查是否满足测试条件
    - 如满足则(IP) ← (IP) + 8位位移量，实行循环；
    - 不满足则 退出循环，顺序执行。 

- 循环指令：LOOP OPR
  - 测试条件：(CX) != 0
- 为零或相等时循环指令：LOOPZ(LOOPE) OPR
  - 测试条件：ZF=1 且 (CX) != 0
- 不为零或不相等时循环指令：LOOPNZ(LOOPNE) OPR
  - 测试条件：ZF=0 且 (CX) != 0
---
- LOOP AGAIN <-> DEC CX JNZ AGAIN
---
```
    MOV CX, 10
L1: ……. ; 需要重复执行的若干条指令
    ……
    LOOP L1
```
- 上面的程序将L1到LOOP指令之间的一段程序重复执行10次。指令“MOV CX, 10”称为“装载循环计数器”, 在循环之前完成。
- 如果将上面的程序写成如下的情形：
  ```
  L1: MOV CX, 10
      ……. ; 重复执行的若干条指令
      …… LOOP L1
  ```
  这个程序将无限制地运行下去，称为“死循环”。
---
- 循环结构也称“重复结构”，一般由以下4个部分组成：
  - （1）初始化部分：为循环做准备。
    - 如：累加器清零，设置地址指针和计数器的初始值等。
  - （2）工作部分：实现循环的基本操作。
  - （3）修改部分：修改指针、计数器的值，为下一次循环做准备。
  - （4）控制部分：判断循环条件，确定结束或继续循环。

---
#### 两种结构的循环：
- WHILE循环：
  - 先判断循环条件，条件满足则进入循环
  - 循环次数最少为0次。
- DO-WHILE循环：
  - 先执行工作部分，然后判断循环条件，条件满足则转向工作部分继续循环
  - 循环次数最少1次。
![](R./../res/3.3_do,while循环.png)

- 按照循环结束的条件，有以下两类循环：
  - 计数循环：**循环的次数事先已知**，用一个变量（寄存器或存储器单元）记录循环的次数（称为“循环计数器”）。
  - 条件循环：**循环的次数事先并不确定**，根据某个条件是否满足来决定是否继续循环。

---
### 3.3.1 计数循环  
用循环计数器的值来控制循环，也可以结合其它条件共同控制。
- 【例 2-31】编程计算1+2+3+…+100=？ 结果保存到字变量SUM中。
  ```
        XOR AX,AX     ;累加器清零
        MOV BX,0001H  ;BX←1
        MOV CX,100    ;CX←循环次数100
  AGAIN:ADD AX,BX     ;AX←(AX)+(BX)
        INC BX        ;BX←(BX)+1
        LOOP AGAIN    ;未循环结束，则继续
        MOV SUM,AX    ;循环结束，保存结果
  ```

---
- 【例 3-7】 字节数组ARRAY存放有10 个有符号数，找出最大数送字节变量MAX。


---
### 3.3.3 多重循环
#### 例3-10 冒泡排序
```
DATA SEGMENT
	ARRAY1 DB 15H, 0A7H, 34H, 55H, 90H, 7EH, 3CH, 25H, 56H, 0D6H
	N EQU $ - ARRAY1
DATA ENDS
CODE SEGMENT
  ASSUME CS:CODE, DS:DATA
START:  MOV AX, DATA
        MOV DS, AX
; **** 开始排序 ****
        MOV CX,N-1  ; 设置外层循环计数器,CX中为排序的"遍数"(N-1)
; ==== 外层循环循环体开始 ====
LOOP1:  PUSH CX     ; 保存外循环计数器
        MOV BX, 0   ; BX=整序元素在数组内的位移,每一遍从第一个元素开始
; ---- 内层循环循环体开始,CX的值是内层循环的次数 ----
LOOP2:  MOV AL, ARRAY1[BX]
        CMP AL, ARRAY1[BX+1] ; 邻元素比较
        JLE NEXT    ; 不需要整序,转NEXT
        XCHG AL,ARRAY1[BX+1]; 交换相邻元素位置
        XCHG AL,ARRAY1[BX]
NEXT:   INC BX      ; 修改指针
        LOOP LOOP2  ; 本遍未结束,转LOOP2继续
; ---- 内层循环循环体结束 ----
        POP CX      ; 恢复外层循环计数器
        LOOP LOOP1  ; "遍数"未满,转LOOP1继续
; ==== 外层循环循环体结束 ====
        MOV AX,4C00H
        INT 21H
CODE ENDS
  END START 
```
---
## 3.4 子程序设计
### 3.4.1 子程序的编写与应用
#### 1. 子程序调用与返回指令
- 子程序是完成特定功能的一段程序
- 当主程序（调用程序）需要执行这个功能时，采用CALL调用指令转移到该子程序的起始处执行
- 当运行完子程序功能后，采用RET返回指令回到主程序继续执行
- > 转移指令有去无回
- > 子程序调用需要返回，其中**利用堆栈保存返回地址** 

---
#### 主程序与子程序
![](R./../res/3.4.1_主程序与子程序.png)

---
#### 子程序定义
- 子程序定义伪操作
  ```
  子程序名 PROC 属 性
  …… ; 子程序体
  子程序名 ENDP
  ```
- 子程序名： 子程序入口的符号地址。子程序名应为合法的标识符，**子程序名不能与同一个源程序中的标号、变量名、其它子程序名相同。**
- 属 性：类型 属 性（NEAR、FAR）
  - **NEAR**： 调用程序和子程序在同一个代码段中（段内调用），缺省为NEAR属性，可以省略。
  - **FAR**：调用程序和子程序不在同一个代码段中（段间调用）

---
#### 近程子程序  
（属性为NEAR 型）
  - **只能被同一个代码段里的程序调用**的子程序。
  - 由于主程序和子程序处于同一个代码段，调用和返回时**只需要改变IP寄存器的值**，CS寄存器的值保持不变。
  - 近程子程序的**入口地址用16位段内偏移地址表示**。

---
#### 远程子程序：   
（属性为FAR 型）
  - **能够被不同代码段的程序调用，也能被同一代码段的程序调用的子程序。** 
  - 调用这样的子程序时，**需要同时改变CS和IP寄存器的值**，返回时，需要从堆栈里弹出32位的返回地址送入IP，CS寄存器。
  - 远程子程序的入口地址用**16位段基址和16位段内偏移地址**表示

---
#### 子程序调用和返回指令
![](R/../res/子程序调用和返回指令.png)


---
## 2.11 中断指令与系统功能调用
### 1. 中断指令和系统功能调用
- 中断（Interrupt）是又一种改变程序执行顺序的方法
- 8086/8088 CPU支持256个中断，每个中断用一个编号（中断向量号）区别
- 中断指令有3条：  
  INT IRET INTO
- 要求掌握中断调用指令**INT** ，进而掌握**系统功能调用**
- 中断向量：  
  中断服务程序的入口地址，存放于中断向量表区。
  ![](R./../res/中断向量表.png)
- 中断指令：  
   INT TYPE
  - 执行操作：  
    ```
    (SP) ← (SP) - 2
    ( (SP)+1,(SP) ) ← (FLAGS)
    (SP) ← (SP) - 2
    ( (SP)+1,(SP) ) ← (CS)
    (SP) ← (SP) - 2
    ( (SP)+1,(SP) ) ← (IP)
    (IP) ← (TYPE*4)
    (CS) ← (TYPE*4+2)
    ```
  - 注意：
    - **TYPE (0~255)** 是中断类型号。根据TYPE ，在中断向量表中找到它所对应的中断向量，即得到所要执行的程序段的段基地址：段偏移地址
    - INT 指令还把 IF 和 TF 置0，但不影响其它标志位
- 中断返回指令：**IRET**
  - 执行操作：  
    ```
    (IP) ← ( (SP)+1,(SP) )
    (SP) ← (SP) + 2
    (CS) ← ( (SP)+1,(SP) )
    (SP) ← (SP) + 2
    (FLAGS) ← ( (SP)+1,(SP) )
    (SP) ← (SP) + 2
    ```
    - 注意：
      - IRET 指令执行完，标志位由堆栈中取出的值确定

---
### 2. 基本I/O功能调用
- DOS系统功能调用
  - DOS利用**21H号**中断提供给用户近百个系统功能，主要包括设备管理、目录管理和文件管理三个方面的功能
- ROM-BIOS系统功能调用
  - ROM-BIOS也以中断服务程序的形式，向程序员提供系统的基本输入输出程序
  - ROM-BIOS功能更加基本，且与操作系统无关
  - 当DOS没有启动或不允许使用DOS功能调用时，可以使用ROM-BIOS功能调用

---
#### BIOS和DOS基本调用
调用方法：
1. 将**调用参数**装入**指定的**寄存器中；
2. BIOS或DOS**功能号**装入**AH**；
3. 如需**子功能号**，把它装入**AL**；
4. 按中断号**调用**DOS或BIOS中断(**INT**);
5. 检查或取得**返回参数**。
![](R./../res/子程序调用与DOSBIOS调用.png)
![](R./../res/DOS常用输入输出功能调用.png)

---
- （1）输出单个字符显示
  ```
  DL ← 待输出字符的ASCII代码
  AH ← 02H
  INT 21H
  DL ← 待输出字符的ASCII代码
  AH ← 02H
  INT 21H
  ``` 
  - 例：下面的程序在显示器上输出数字字符“9”：
    ```
    MOV AH, 2 ；功能号02H
    MOV DL, 39H ；字符“9”的ASCII代码
    INT 21H ；调用21H号系统服务程序
    ```
    - 字符“9”显示在光标(Cursor)位置，光标向右移动一个字符位置。
  - X为DB定义的一个变量，下面的程序能够输出X的值吗？
    ```
    MOV AH, 2 ；功能号02H装入AH寄存器
    MOV DL, X ；变量X的值装入DL寄存器
    INT 21H ；调用21H号系统服务程序
    ```
  - [例] 在显示器上输出文字“Hello !”
    ```
    CODE SEGMENT
          ASSUME CS: CODE
    START:LEA BX, STRING
          MOV CX, 7
    ONE:  MOV DL, CS: [BX] ；取出一个字符的ASCII代码
          MOV AH, 2 ；单个字符输出的功能号
          INT 21H ；调用系统服务，输出一个字符
          INC BX ；修改指针
          LOOP ONE ；计数与循环控制
          MOV AX, 4C00H
          INT 21H
    STRING DB “Hello !”
    CODE ENDS
          END START
    ``` 
  - STRING在代码段里定义，取字符需要增加段跨越前缀“CS: [BX]”，否则会到“DS: [BX]”处取字符，输出不确定的内容。
  - 代码为0DH的字符称为“回车（Carriage Return, CR）”，把光标移动到本行的第一个字符位置，
  - 代码为0AH的字符称为“换行（Line Feed, LF）”，把光标移动到下一行的相同位置上
    ```
    MOV CX, 11  
    ……
    STRING DB 0DH, 0AH, “Hello !”, 0DH, 0AH
    ```
---
- （2）输出一个字符串
  ```
  DS: DX ← 待输出字符串的首地址
  AH ← 09H
  INT 21H
  ```
  字符串以字符“$”为结束标志，该字符本身不输出。
  ```
  CODE SEGMENT
        ASSUME CS: CODE, DS: CODE
  START:MOV AX, CODE
        MOV DS, AX
        LEA DX, STRING
        MOV AH, 9
        INT 21H
        MOV AX, 4C00H
        INT 21H
        STRING DB 0AH, 0DH, “Hello !”, 0AH, 0DH, ‘$’
  CODE ENDS
        END START
  ```
  - [例] 从键盘输入5个数字（0到9之间），求它们的和，存入SUM。
    ```
    DATA SEGMENT
      SUM DB ?
    DATA ENDS
    ； --------------------------------------------- 
    CODE SEGMENT
          ASSUME DS: DATA, CS: CODE
    START:MOV AX, DATA
          MOV DS, AX
          MOV CX, 5   ；循环次数
          MOV SUM, 0  ；累加器清零
    ONE:  MOV AH, 1   ；输入单个字符的功能号
          INT 21H     ；输入一个字符，ASCII码在AL中
          AND AL, 0FH ；ASCII码转换成二进制数
          ADD SUM, AL ；累加
          LOOP ONE    ；计数与循环
          MOV AX, 4C00H
          INT 21H
    CODE ENDS
          END START
    ```
  ---
  - 2-28 试编写一个汇编语言程序,要求将键盘输入的小写字母用大些字母显示出来
    ```
    CODE SEGMENT
        ASSUME CS:CODE
    START:MOV AH,01H
          INT 21H
          CMP AL, 0DH   ; 输入回车退出程序
          JZ EXIT 
          CMP AL, 'a'   ; 小于小写字母a,不需要处理
          JB EXIT
          CMP AL, 'z'   ; 大于小写字母z,也不需要处理
          JA EXIT
          SUB AL, 20H   ; 是小写字母,则转换为大写
          MOV DL, AL
          MOV AH, 02H
          INT 21H
          JMP START
    EXIT: MOV AX, 4C00H
          INT 21H
    CODE ENDS
          END START
    ```

---
### 小结
- 中断与中断返回指令
  - INT、IRET
- 常用DOS功能调用（ **INT 21H**） 
  - 字符输入：1号调用
  - 字符输出：2号调用
  - 字符串输出：9号调用

---
## 10.19随笔
- BP指令默认访问堆栈段
- 8086中push指令不支持立即数寻址
  - push指令不可与offset混用

