 
 
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

```
.model tiny
.stack 100
.code
EXTRN   initkeydisplay:near
        display8:near
DATAS SEGMENT
    buf db 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h
    done db 00h'
DATAS ENDS
STACKS SEGMENT
STACKS ENDS
CODES SEGMENT
ASSUME CS:CODES, DS:DATAS, SS:STACKS
start:
    mov ax, 0
    mov es, ax
    mov bx, 42h * 4
    mov ax, offset cnt
    mov es:[bx], ax
    mov ax, seg cnt
    mov es:[bx + 2], ax
    ;8255初始化
    extrn InitKeyDisplay
    ;8259初始化
    mov al, 13h
    out 80h, al
    mov al, 40h
    out 82h, al
    mov al, 01h
    out 82h, al
    mov si, offset buf
    mov bx, 0
    sti
wait0:
    extrn Display8
    cmp done, 9
    jnz wait0
    hlt

cnt proc near
    sti
    add done, 1
    mov al, done
    mov [bx], al
    cli
    mov al, 20h
    out 80h, al
    iret
cnt endp

CODES ENDS
    END START

```


```
.model tiny
.stack 100
.code
EXTRN   initkeydisplay:near
DATAS SEGMENT
    buf db 00h, 00h, 00h, 00h, 00h, 00h, 00h, 00h
    done db 00h
DATAS ENDS
STACKS SEGMENT
STACKS ENDS
CODES SEGMENT
ASSUME CS:CODES, DS:DATAS, SS:STACKS
start:
    mov ax, 0
    mov es, ax
    mov bx, 42h * 4
    mov ax, offset cnt
    mov es:[bx], ax
    mov ax, seg cnt
    mov es:[bx + 2], ax
    ;8255初始化
    ;8259初始化
    mov al, 13h
    out 80h, al
    mov al, 40h
    out 82h, al
    mov al, 01h
    out 82h, al
    mov si, offset buf
    mov bx, 0
    sti
wait0:
    extrn Display8
    cmp done, 9
    jnz wait0
    hlt

cnt proc near
    sti
    add done, 1
    mov al, done
    mov [bx], al
    cli
    mov al, 20h
    out 80h, al
    iret
cnt endp

CODES ENDS
    END START
```

```
.model tiny
.stack 100
.data
		array DB 10 dup(?)
.code
start:
		mov ax,@data
		lea bx, array
		mov cx, 10
		mov al, 10000110b
		mov dx,273h		;¿ØÖÆ×Ö¶Ë¿ÚµØÖ·
		out dx, al
loop1:	 	mov dx, 272h
		in al, dx
		in al, 00000010
		jz loop1
		mov dx, 271h
		in al, dx
		mov [bx], al
		inc bx
		nop
		loop loop1
			
		hlt
end start



```




```
.model tiny
.stack 100
.code
	EXTRN InitKeyDisplay:near,Display8:near
	buffer db 00h, 10h, 10h, 10h, 10h, 10h, 10h, 10h
	done db 00h
	io82590 equ 0250h
	io82591 equ 0251h
	
start:	mov ax, @data
	mov ds, ax
	mov ax, 0
	mov es, ax
	mov bx, 42h * 4
	mov ax, offset cnt
	mov es:[bx], ax
	mov ax, seg cnt
	mov es:[bx + 2], ax
	;8255³õÊ¼
	call InitKeyDisplay
	;8259³õÊ¼
	call Init8259
	mov si, offset buffer
	sti
	
wait0:
	call Display8
	cmp done, 9
	jnz wait0
	hlt

Init8259 proc near
	mov al, 13h
	mov dx, io82590
	out dx, al
	mov al, 40h
	mov dx, io82591
	out dx, al
	mov al, 01h
	out dx, al
	ret
Init8259 endp

cnt proc near
	sti
	add done, 1
	mov al, done
	mov bx, 0
	mov [bx], al
	cli
	mov al, 20h
	mov dx, io82590
	out dx, al
	iret
cnt endp

end start

```


```
.model tiny
.stack 100
.code
	BUFF DB 0
start:
	mov ax,@data
	mov ds,ax
	
	mov bx,0;BX寄存器用于计数
	mov si,offset BUFF
	;设置方式控制字
	mov dx,273h;控制字端口地址
	mov al,86h;端口B方式1输入控制字
	out dx,al
	mov dx,272h
wait0:	in al,dx;读端口C状态
	test al,2
	jz wait0;PC1=0等待
	mov dx,271h;PC1=1则开始读入
	in al,dx
	mov [si],al
	inc si
	inc bx
	mov dx,272h
	cmp bx,10;比较是否读入10次
	jnz wait0
	
	hlt
end start

```

---
# 实验5 键盘按键与数码管显示
## 实验要求
- 在2行8列的小键盘上人已按下某个按键,该键的值将同时显示在8个数码管上.按键松开时显示上一次的按键值;

---
```
.MODEL TINY 
.DATA
    SEGTAB DB 0C0H,0F9H,0A4H,0B0H,99H,
              92H,82H,0F8H,80H,90H,88H,
              0H,0C6H,40H,86H,8EH       ; LED灯编码
    KEYCODE DW 0FE02H,0FD02H,0FB02H,0F702H,0EF02H,
               0DF02H,0BF02H,7F02H,0FE01H,0FD01H,
               0FB01H,0F701H,0EF01H,0DF01H,0BF01H,7F01H    ; 键盘列行码  
    A EQU 270H      ; 8255各控制端口地址  
    B EQU 271H
    C EQU 272H
    CON EQU 273H
    COUNT DW 1      ; 延时程序参数 
.STACK 100
.CODE

START:
    MOV AX, @DATA
    MOV DS,AX
    MOV DX,CON      ; 设置8255工作方式A，B端输出，PC0，PC1输入，方式0  
    MOV AL,81H
    OUT DX,AL

WAITE: 
    CALL SCANKEY    ; 扫描件键盘子程序  
    CMP AX,-1
    JZ WAITE 
    CALL TRANSLATE ; 列行码转化为LED灯编码子程序  
    CALL LED_DISP   ; LED显示程序  
    JMP WAITE  
    MOV AX, 4C00H  
    INT 21H  
    
SCANKEY PROC  
    PUSH CX  
    PUSH DX  
    MOV DX,B    ; MOV AL,0FH    经过测试去掉此步骤，在其它实验设备上可以完整显示  
                ; OUT DX,AL     硬件设备有错，这两句用以在错误的硬件电路上完整的显示结果  
    MOV AL,0 
    OUT DX,AL   ; 列输出全“0”  
    MOV DX,C  
    IN AL,DX    ; 读取行端口  
    AND AL,03H  
    CMP AL,3H   ; 检测列信息是否全“1”，判断有无按键  
    JZ NO_KEY   ; 无按键时，转移后返回“-1”  
    ;延时20ms  
    CALL DELAY 
    IN AL,DX    ;读取行端口  
    AND AL,03H
    CMP AL,3H   ;检测列信息是否全“1”，判断有无按键  
    JZ NO_KEY   ;无按键时，转移后返回“-1”  
    MOV AH,0FEH  
    MOV CX,8 
    
NEXT:
    MOV AL,AH  
    ROL AH,1  
    MOV DX,B  
    OUT DX,AL  
    MOV DX,C  
    IN AL,DX    ; 读取行码  
    AND AL,03H  
    CMP AL,3H 
    LOOPZ NEXT  
    JZ NO_KEY   ; 没有按键，转以后返回“-1”  
    ROR AH,1    ; AX存放形成的列行码  
    JMP EXIT 
    
NO_KEY:   
    MOV AX,-1  

EXIT: 
    POP DX  
    POP CX  
    RET 
    SCANKEY ENDP  
    
TRANSLATE PROC  
    PUSH CX  
    PUSH SI  
    PUSH DI  
    MOV CX,16  
    LEA SI,SEGTAB-1  
    LEA DI,KEYCODE-2 
    
SCANTAB:
    INC SI  
    INC DI  
    INC DI 
    CMP AX,[DI]  
    LOOPNZ SCANTAB  
    JNZ QUIT  
    MOV DL,[SI]     ; 得到要显示的段码 

QUIT: 
    POP DI  
    POP SI  
    POP CX  
    RET  
    TRANSLATE ENDP   
    
LED_DISP PROC  
    PUSH BX  
    PUSH AX  
    MOV BL,DL  
    MOV AL,0FFH ;每次调用显示子程序先关闭一次显示  
    MOV DX,B  
    OUT DX,AL  
    MOV AL,BL  
    MOV DX,A  
    OUT DX,AL  
    MOV AL,0H   ;显示所有位，实际上在本程序里起实际作用的是扫描子程序里的列输出全0的那个操作  
    MOV DX,B  
    OUT DX,AL  
    POP AX  
    POP BX  
    RET  
LED_DISP ENDP  

DELAY PROC  
    MOV CX,COUNT 
    
DELAY1: 
    LOOP DELAY1  
DELAY ENDP   
    END START 

```
