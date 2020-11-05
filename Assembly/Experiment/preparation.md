# 前言
- 时间：8-15周，周五1,2节
- 地点：计算机205
- 前三个是软件编程（在同一个预习文件里），需要提前编好程序，上课时调试
- 所有材料都要打印，实验报告必须正反打印，一份报告一张纸

---
## 具体实验相关
- 必须放在E/F的一级子目录下
- 程序最开头必须是:
```
.model tiny
.stack  100
.code
```
- 程序段之后加上
```
PC->HLT ; 星研系统要求最后这样中断程序,才可以去存储窗口查看数据
```


# 实验1  分支程序设计
## 实验要求
- 从下面两题选做一题,编写完整程序并提哦啊哈斯通过
  - 统计有符号字节数组中负数和非负数的个数
  - 求有符号字数组中绝对值最大的一个数据
## 代码1
```
.MODEL TINY
.STACK 100
.CODE
DATA SEGMENT
    ARRAY DB 1,-2,-4,8,6,0,127,-128,5,-3
    PLUS DB 0   ; 非负数
    MINUS DB 0  ; 负数
DATA ENDS
CODE SEGMENT
  ASSUME CS:CODE, DS:DATA
      ;先将要用的变量清零
START:MOV AX, DATA
      MOV DS, AX
      XOR AL,AL     ; AL累加器低八位
      XOR PLUS,AL   ; 
      XOR MINUS,AL
      LEA SI,ARRAY  ;设置地址指针(SI:源变址寄存器)
      MOV CX,10	    ;设置循环次数(CX:计数寄存器)
CHECK:MOV AL,[SI]   ;取出数组里的第一个数
      AND AL,AL      
      JS MS         ;判断正负(SIGN=1是负数则转移)
      INC PLUS      ;非负数的个数
      JMP NEXT
   MS:INC MINUS     ;负数的个数,语句体2
      JMP NEXT
;SI取的时候ARRAY的首地址,本质上是ARRAY首地址的引用
;因此取数组中下一个数的操作可以是INC SI(SI=SI+1)
 NEXT:INC SI        
      DEC CX        ;CX=CX-1,循环次数-1
;DEC指令影响ZF,下面循环结束判断直接判断ZF
      JNZ CHECK     ;当前ZERO!=0时跳转回CHECK
CODE  ENDS
      END START
PC->HLT
```



## 代码2(×)
```
MAXABS PROC
        PUSH CX ; CX计数寄存器
        PUSH SI ; SI源变址寄存器
        PUSH DX ; DX数据寄存器
        POP ES  ; ES附加段寄存器
        XOR AX,AX   ; AX累加器
NEXT:   MOV BX, WORD PTR[SI]    ; BX基址寄存器
        AND BX,BX
        JZ OK
        NEG BX
OK:     CMP BX, AX
        JLE SKIP
        MOV AX, BX
        MOV DI, SI
SKIP:   ADD SI, 2
        LOOP NEXT
        POP SI
        POP CX
        RET
MAXABS ENDP
```

---
# 实验2 循环程序设计
## 实验要求


## 代码(冒泡排序)
```
.MODEL TINY
.STACK 100
.CODE
DATA SEGMENT
    ARRAY DW 1,-2,-4,8,6,0,127,-128,5,-3
    N EQU 10
DATA ENDS
CODE SEGMENT
  ASSUME CS:CODE, DS:DATA
      ;先将要用的变量清零
START:MOV AX, DATA
      MOV DS, AX
      MOV CX, 9
LOOP1:PUSH CX     ; 保护计数器
      MOV BX, 0
LOOP2:MOV AX, ARRAY[BX]
      CMP AX, ARRAY[BX+2]  ; 相邻元素比较(字数据所以+2)
      JLE NEXT
      XCHG AX, ARRAY[BX+2]    ; 交换位置
      XCHG AX, ARRAY[BX]
NEXT: INC BX
      INC BX
      LOOP LOOP2
      POP CX
      LOOP LOOP1
      HLT
CODE ENDS
      END START
```