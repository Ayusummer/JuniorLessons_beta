# 第2章
## 9.28随堂练习
### 编写程序段，求以下变量表达式的值，所有变量均为有符号字变量:Z = ( X + Y)/W - S*Y
- 正确答案:
```
MOV AX, X
ADD AX, Y      ; X + Y (1分)
CWD
IDIV  W        ; ( X + Y)/W (2分)  
CWD    
MOV CX, DX
MOV BX,  AX    ;暂存( X + Y)/W (2分)
MOV AX, S
IMUL Y         ; S*Y (2分)
SUB  BX, AX
SBB CX, DX    ; ( X + Y)/W - S*Y (2分)
MOV Z, BX 
MOV Z+2, CX
```
## 9.28课后练习    
- P87,2-14(2)  
写出实现下列计算的指令序列。（假定X、Y、Z、W、R都为有符号字变量）
Z = 2*（W-X）/（5*Y）
```
MOV AX,Y
MOV BX,5
IMUL BX
MOV BX,AX   ;暂存5Y 
MOV AX,W
SUB AX,X
CWD
IDIV BX
CWD
MOV BX,AX
MOV AX,2
IMUL BX
MOV Z,AX
```
- 参考答案
  ```
  MOV AX, W
  SUB AX, X   ; W-X,结果在AX中
  SAL AX,1    ; 2(W-X), 结果在AX中
  MOV BX, Y
  MOV CL, 2
  SAL BX, CL  ; 4Y
  ADD BX, Y   ; 5Y
  CWD         ; 2(W-X),扩展,结果在DX,AX中
  IDIV BX     ; 2(W-X)/(5Y),结果在AX中
  MOV Z, AX

  ```
- 8086乘除法指令不支持立即寻址
  - 如IMUL 2
    - 这条指令是错误的
- SAL
  - 算数左移指令
- 当移位指令移位次数>2时用CL
  - 移位指令第二位只能是1或者CL


## 2.7  8086/8088指令系统
### 2.7.3 逻辑运算类指令
#### 逻辑运算指令预习检测
- 1.已知
  ```
  (AX)= 0FF60H，CF = 1。
  MOV DX, 96
  XOR DH, 0FFH
  SBB AX, DX
  ```
  上述程序段执行后：（AX）= ?，CF = ?。
  - 答案:(AX) = 0 , CF = 0;
  - MOV DX,96
    - DX <- 60H
    - XOR DH,OFFH
    - 
    - **CF置零**
  -      

  -  XOR DX,96
    - XOR 96,96 = 0  

- 2.将CX寄存器低4位清零的正确指令是?
  - 答案:AND CX，0FFF0H

- 3.下列指令执行后既能使AX=0同时又使CF=0,OF=0的是?
  - 答案:XOR AX，AX

- 4.AND，OR，XOR，NOT为四条逻辑运算指令，下面的解释正确的是?
  - 答案:指令AND AX，OFH执行后，分离出AL低四位  

- 5.无论BH中原有的数是奇数或偶数，若要使BH中的数一定为奇数，应执行的指令是?
  - OR BH，01H

- 6.设AL=0AH，下列指令执行后能使AL=05H的是?
  - 答案:XOR AL，0FH 
  - NOT整体取反
    - NOT AL -> F5H

- 7.执行“and al,80h”指令后，可以肯定的执行结果是AL寄存器的?
  - 答案:A.低7位均为0

- 8.下列指令中，执行后对标志不发生影响的是
  - mov指令不影响标志位
---
#### 移位指令预习检测
- 1.将AX中有符号数除以2的正确指令是?
  -  SAR AX，1
  -  > 逻辑左移一位相当于无符号数乘以2  
     > 逻辑右移一位相当于无符号数除以2  
     > 算术左移一位相当于有符号数乘以2  
     > 算术右移一位相当于有符号数除以2    

- 2.算术右移指令SAR和逻辑右移指令SHR，两条指令执行结果完全相同的条件是?
  - 目的操作数最高位为0

- 3.下面两条指令执行后，DA2中两字节单元内容分别是?
    ```   
    DA1 EQU WORD PTR DA2
    DA2 DB OABH，OCDH
    SHL DA1，1
    SHR DA2，1
    ```
    - 2BH，9BH
    - .
  
- 4.下列指令执行后影响CF值的是?
  - SHL 
  - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_aa2b4439d0be890688f80b159a73047c.png)

- 5.设CL＝8，AL=0C8H，执行SAR AL，CL后，AL中的数据是?
  - 0FFH
  - 每一动都在最高位补充符号位,总共八位移位八位高位补齐了1 

- 6.完成对CL寄存器的内容乘以4的正确操作是
```
SHL CL，1
SHL CL，1 
```

- 7.能将CF标志位移入AL最低位的指令是?
  - rcl al, 1
  - ![](https://codimd.s3.shivering-isles.com/demo/uploads/upload_f0f0c78a2ecb9ca925d127de42eba474.png)

- 8.SHL指令左移一位，就是乘10。
  - 错
  - *2 

---
## 2.8 转移指令与分支程序设计
### 转移指令1
- 1.​JA和JG指令的条件都是“大于”，所以是同一个指令的两个助记符。
  - (×) 
- 2.在双分支程序结构中，顺序执行的分支体最后需要JMP指令，目的是使第一个分支体执行结束之后，跳过第二个分支体，避免误入第二个分支体中。
  - (√) 
- 3.对无符号数和有符号数进行加减采用同样的指令，所以比较两者大小的条件转移指令也可以采用同样的指令。
  - (×)
- 4. 执行JNS指令顺序执行的条件是SF＝1 。
  - (√) 
- 5.执行JNZ指令发生转移的条件是ZF＝1 。
  - (×) 
- 6.条件转移指令JC和JB虽然是两个助记符，但却是同一条指令。
  - (√) 
- 7. CS不变，只改变IP值，不能改变程序的执行顺序。
  - (×)
- 8.指令指针IP或者还包括代码段寄存器CS值的改变将引起程序流程的改变。
  - (√) 

--- 
### 转移指令2
- 1.转移指令JMP NEAR PTR PROCA的转移范围是?
  - 8000H～7FFFH
- 2.无条件转移指令JMP实现段间间接转移，转移的目标地址在?
  - 某个双字存储单元中
- 3必答 (单选题) 已知again是一个标号，则指令”jmp again”中，again不包含?
- byte或者dword类型
- 4.在一段顺序结构的程序中，不应该出现的指令是? 
  - jz
- 5.MASM中，实现段间转移的转移类型属性是?
  - FAR
- 6.使用CMP指令比较两个有符号数之后，程序希望“大于”时发生转移，则应该使用的条件转移指令是?
  - JG
- 7.当逻辑运算AND指令执行后，低8位结果中“1”的个数是零或偶数发生转移的指令是?
  - JP
- 8.JCXZ指令发生转移的条件是?
  - CX＝0
- 9.如果AX＝100、DX＝200时，执行“CMP AX, DX”指令，接着(   )条件转移指令会发生控制转移。
  - JB
- 10.条件转移指令JNBE产生转移的条件是（    ）
  - CF=0 AND ZF=0

---
## 10.5课后练习题
- ARRAY为数据段中定义的有符号字节数组，存放了100个字节数据。  试编写指令序列，统计ARRAY数组中正数、负数和0的个数，分别存放在PLUS、MINUS和ZERO三个字节变量中。
```
;个人答案:
        LEA SI,ARRAY
        MOV CX,100    
CYCLE:  MOV AL,[SI]
        CALL LES
        LOOP AGAIN
LES:    CMP AL,0
        JGE BIGER
        INC MINUS
        RET
BIGER:  JE OK
        INC PLUS
        RET
   OK:  INC ZERO
        RET
```
```
;老师的答案
      ;先将要用的变量清零
      XOR AL,AL     
      XOR PLUS,AL
      XOR MINUS,AL
      XOR ZERO,AL
      LEA SI,ARRAY  ;设置地址指针(SI:源变址寄存器)
      MOV CX,100    ;设置循环次数(CX:计数寄存器)
CHECK:MOV AL,[SI]   ;取出数组里的第一个数
      AND AL,AL
      JS MS         ;判断正负(SIGN=1是负数则转移)
      JZ ZO         ;判断0(ZERO=1是0则转移)
      INC PLUS      ;正数的个数
      JMP NEXT
  MS: INC MINUS     ;负数的个数,语句体2
      JMP NEXT
  ZO: INC ZERO      ;0的个数,语句体3
;SI取的时候ARRAY的首地址,本质上是ARRAY首地址的引用
;因此取数组中下一个数的操作可以是INC SI(SI=SI+1)
NEXT: INC SI        
      DEC CX        ;CX=CX-1,循环次数-1
;DEC指令影响ZF,下面循环结束判断直接判断ZF
      JNZ CHECK     ;当前ZERO!=0时跳转回CHECK
```
> 最好不用BP(基址指针寄存器)

```
;使用循环结构
      XOR AL,AL ;清零
      MOV PLUS,AL
      MOV MINUS AL
      MOV ZERO,AL
      LEA SI,ARRAY
      MOV CX,100 
CHECK:MOV AL.[SI]
      AND AL,AL
      JS MS     ;判断正负
      JZ ZO
      INC PLUS  ;正数的个数,语句体1
      JMP NEXT
  MS: INC MINUS ;负数的个数,语句体2
      JMP NEXT
  ZO: INC ZERO  ;0的个数,语句体3
NEXT: INC SI
      DEC CX
      JNZ CHECK
```
> DEC CX JNZ CHECK 等价于LOOP CHECK

---
# 第3章
## 3.3 循环程序设计
### 10.12 预习检测 循环控制1
- 1.循环控制指令LoopNZ/LoopNE控制循环继续执行的条件是?
  - CX≠0且ZF=0
- 2.使用LOOP指令控制计数循环，循环次数应赋予的寄存器是?
  - CX
- 3.若CX＝0，则语句“AGAIN: LOOP AGAIN”将会重复执行?次。 
  - $2^{16}$  
- 4.判断循环是否结束的循环控制部分只能安排在循环体之后。
  - ×
- 5.通常循环体中应该包含进行循环条件修改的代码。
  - √

---
## 3.4 子程序设计
### 10.14 预习检测 子程序1
- 1.设（SP）=0028H，执行段内返回指令RET 8后，SP的内容是?
  - 0032H
  - RET指针会使SP+2
  - 0028H+8+2=0032H
- 2.call指令执行后，堆栈的栈顶内容为?
  - call指令的下一条指令的地址
  - call指令利用堆栈保存地址,保存了call指令下条指令的地址
- 3.CALL指令的执行并不影响堆栈指针SP。
  - (×)
- 4.过程定义PROC是一条MASM伪指令。
  - (√)
- 5. 进入子程序后，将AX、BX、CX和DX按顺序压入堆栈，则子程序返回前弹出这些寄存器的顺序还是AX、BX、CX和DX。
  - (×)


---
### 子程序设计20201019
- 1.内存中在以BLOCK为首地址处存放100个无符号字节数。试编写一程序，求出该数组中的最大数与最小数的差，并将其送入RESULT单元，要求调用子程序来完成对最大数和最小数的求解。
```
DATA SEGMENT
  BLOCK DB 46,37,29,56,25,35,11,27,66,42,82,61
  COUNT EQU $-BLOCK
  RESULT DB 0
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
  START:  MOV AX,DATA
          MOV DS,AX
          LEA SI, BLOCK
          MOV CX, COUNT
          CALL MAXMIN
          SUB AH,AL
          MOV RESULT, AH
  EXIT:   MOV AX, 4C00H
          INT 21H
  MAXMIN PROC
          MOV AH, 0 
          MOV AL, 255
  AGAIN:  MOV DL, [SI]
          CMP AL,DL
          JBE ABOVE
          MOV AL, DL      ; 小于当前最小值则替换
  ABOVE:  CMP AH, DL
          JAE BELOW
          MOV AH, DL      ; 大于当前最大值则替换
  BELOW:  INC SI
          LOOP AGAIN
          RET
  MAXMIN ENDP
CODEENDS
          END START
```



- 2.某年级参加英语4级考试的有250名学生，试编写一程序完成60-69，70-79，80-89，90-100四个分数段的统计工作，要求用子程序完成每个分数段的统计工作。
```
DATA SEGMENT
    BLOCK DB 66,75,89,62,77,82,95,73,99
    C60 DB 0  ; 60-70
    C70 DB 0  ; 70-80
    C80 DB 0  ; 80-90
    C90 DB 0  ; 90-100
DATA ENDS
CODE SEGMENT
  ASSUME CS:CODE, DS:DATA
  START:  MOV AX, DATA
          MOV DS, AX
          MOV CX, 4
          LEA DI, C60
          MOV AL, 60
  STATS:  LEA SI, BLOCK
          CALL COUNT
          MOV [DI], DL
          ADD AL, 10
          INC DI
          LOOP STATS
  EXIT:   MOV AX, 4C00H
          INT 21H
  COUNT PROC
          PUSH CX
          MOV CX, 15
          MOV DL, 0
          MOV AH, AL
          ADD AH, 9
          CMP AH, 99
          JNZ CONTIN
          INC AH
  CONTIN: CMP [SI], AL
          JB NEXT
          CMP [SI], AH
          JA NEXT
          INC DL
  NEXT:   INC SI
          LOOP CONTIN
          POP CX
          RET
  COUNT ENDP
  CODE ENDS
          END START
```