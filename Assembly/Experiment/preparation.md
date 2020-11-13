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
LOOP2:MOV AX, ARRAY  [BX]
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

---
# 实验3 子程序设计
```
.model tiny
.stack 100
.code
DATAS SEGMENT
    PNUM DB '这是一个素数',0AH,0DH,'$'
    NOPNUM DB '这不是一个素数  !',0AH,0DH,'$'
    NUM DW 20 DUP(?)  
DATAS ENDS
STACKS SEGMENT
STACKS ENDS
CODES SEGMENT
ASSUME CS:CODES, DS:DATAS, SS:STACKS
START:
MOV AX , DATAS
MOV DS,AX
EGA:LEA SI,NUM
    CALL CODE1
    MOV SI,NUM
    CALL CODE2
    CMP DX,0
    JZ CVE
    LEA DX,PNUM
    MOV AH,09H
    INT 21H
    JMP DVE
CVE:LEA DX,NOPNUM
    MOV AH,09H
    INT 21H
DVE:MOV NUM,0
    JMP EGA
    MOV AH,4CH
    INT 21H
CODE1 PROC        ; 输入数据
    MOV CX,10     ; 
AGA:MOV AH,01H
    MOV AL,00H
    INT 21H       ; 回显字符输入
    CMP AL,30H    ; 与1的ASCII码比较
    JB OVE        ; 若小于则退出
    CMP AL,39H
    JA OVE
    CBW
    SUB AX,30H
    PUSH AX
    MOV AX,[SI]
    MUL CX
    POP DX
    ADD AX,DX
    MOV [SI],AX
    JMP AGA
OVE:RET
CODE1 ENDP

CODE2 PROC
    SUB SI,2
    MOV CX,SI
    MOV BX,2
    ADD SI,2
BAG:MOV AX,SI  
    CWD
    DIV BX
    CMP DX,0
    JZ AVE
    INC BX
    LOOP BAG
    MOV DX,1
    JMP BVE
AVE:MOV DX,0
BVE:RET
CODE2 ENDP
CODES ENDS
    END START
```
```
.model tiny
.stack 100
.code
DATAS SEGMENT
    PNUM DB '这是一个素数',0AH,0DH,'$'
    NOPNUM DB '这不是一个素数  !',0AH,0DH,'$'
    NUM DW 20 DUP(?)  
DATAS ENDS
STACKS SEGMENT
STACKS ENDS
CODES SEGMENT
ASSUME CS:CODES, DS:DATAS, SS:STACKS
START:
MOV AX , DATAS
MOV DS,AX
EGA:LEA SI,NUM
    CALL CODE1
    MOV SI,NUM
    CALL CODE2
    CMP DX,0
    JZ CVE
    LEA DX,PNUM
    MOV AH,09H
    INT 21H
    JMP DVE
CVE:LEA DX,NOPNUM
    MOV AH,09H
    INT 21H
DVE:MOV NUM,0
    JMP EGA
    MOV AH,4CH
    INT 21H
CODE1 PROC        ; 输入数据
    MOV CX,10     ; 
AGA:MOV AH,01H
    MOV AL,00H
    INT 21H       ; 回显字符输入
    CMP AL,30H    ; 与0的ASCII码比较
    JB OVE        ; 若小于则退出
    CMP AL,39H    ; 若不小于则与9的ASCII码比较
    JA OVE        ; 若大于9则退出
    CBW           ; 扩展
    SUB AX,30H    ; AX = AX-30
    PUSH AX       ; AX压栈保护
    MOV AX,[SI]   ; 
    MUL CX
    POP DX
    ADD AX,DX
    MOV [SI],AX
    JMP AGA 
OVE:RET
CODE1 ENDP

CODE2 PROC
    SUB SI,2
    MOV CX,SI
    MOV BX,2
    ADD SI,2
BAG:MOV AX,SI  
    CWD
    DIV BX
    CMP DX,0
    JZ AVE
    INC BX
    LOOP BAG
    MOV DX,1
    JMP BVE
AVE:MOV DX,0
BVE:RET
CODE2 ENDP
CODES ENDS
    END START
```
- 修改版
```
.model tiny
.stack 100
.code
DATAS SEGMENT
    PNUM DB '这是一个素数',0AH,0DH,'$'	
    NOPNUM DB '这不是一个素数',0AH,0DH,'$'	
    NUM DW 20 DUP(?)  
DATAS ENDS
STACKS SEGMENT
STACKS ENDS
CODES SEGMENT
ASSUME CS:CODES, DS:DATAS, SS:STACKS
START:
MOV AX , DATAS
MOV DS,AX
EGA:LEA SI,NUM
    CALL CODE1
    MOV SI,NUM
    CALL CODE2
    CMP DX,0
    JZ CVE
    LEA DX,PNUM
    MOV AH,09H
    INT 21H
    JMP DVE
CVE:LEA DX,NOPNUM
    MOV AH,09H
    INT 21H
DVE:MOV NUM,0
    JMP EGA
    MOV AH,4CH
    INT 21H
CODE1 PROC
    MOV CX,10
AGA:MOV AH,01H
    MOV AL,00H
    INT 21H
    CMP AL,30H
    JB OVE
    CMP AL,39H
    JA OVE
    CBW
    SUB AX,30H
    PUSH AX
    MOV AX,[SI]
    MUL CX
    POP DX
    ADD AX,DX
    MOV [SI],AX
    JMP AGA
OVE:RET
CODE1 ENDP

CODE2 PROC
    SUB SI,2
    MOV CX,SI
    MOV BX,2
    ADD SI,2
    MOV AX,SI
    CMP AX,2
    JZ TRU
BAG:MOV AX,SI  
    CWD
    DIV BX
    CMP DX,0
    JZ AVE
    INC BX
    LOOP BAG
TRU:MOV DX,1
    JMP BVE
AVE:MOV DX,0
BVE:RET
CODE2 ENDP
CODES ENDS
    END START

```