import tkinter as tk    #GUI模块
import tkinter.messagebox
from csv import reader,writer
import os
window=tk.Tk()  #初始化图形界面
window.title('学生成绩管理系统')
name=[] #初始化姓名列表
id=[]   #初始化学号列表
score=[]    #初始化成绩列表

l1=tk.Label(window,text='姓名')    #建立姓名，学号，成绩标签
l2=tk.Label(window,text='学号')
l3=tk.Label(window,text='成绩')
l1.pack()
l2.pack()
l3.pack()

e1=tk.Entry(window,show=None)   #建立姓名，学号，成绩输入框
e2=tk.Entry(window,show=None)
e3=tk.Entry(window,show=None)
e1.pack(after=l1)
e2.pack(after=l2)
e3.pack(after=l3)

def add_score():    #用于添加成绩信息的函数
    if(e1.get()==""):   #若输入为空，则弹出提示框
        tkinter.messagebox.showinfo(title='输入为空',message='请输入学生信息')
        return
    name.append(e1.get())   #从输入框中获取姓名学号成绩信息
    id.append(e2.get())
    score.append(e3.get())
    e1.delete(0, tk.END)    #添加完毕后清空输入框中内容
    e2.delete(0, tk.END)
    e3.delete(0, tk.END)
    text1.insert(tk.END,"---添加成功！---\n(当前共有"+str(len(name))+"条成绩信息)\n")

def show_score():   #展示学生成绩的函数
    text1.insert(tk.END,"\n-----以下为所有学生成绩信息-----\n")
    for i in range(len(name)):  #按顺序输出列表
        text1.insert(tk.END,"姓名：")
        text1.insert(tk.END,name[i])
        text1.insert(tk.END," 学号：")
        text1.insert(tk.END,id[i])
        text1.insert(tk.END," 得分：")
        text1.insert(tk.END,score[i])
        text1.insert(tk.END,'\n')

def show_score_sorted():    #将学生成绩从高到低排序输出
    l4=zip(name,id,score)   #将三个列表合并为一个
    l4=sorted(l4,key=lambda x:int(x[2]),reverse=True)   #将列表按成绩大小排序
    text1.insert(tk.END,"\n-----以下为所有学生成绩信息-----\n")
    for i in range(len(l4)):    #输出排序后的列表
        text1.insert(tk.END,"姓名：")
        text1.insert(tk.END,l4[i][0])
        text1.insert(tk.END," 学号：")
        text1.insert(tk.END,l4[i][1])
        text1.insert(tk.END," 得分：")
        text1.insert(tk.END,l4[i][2])
        text1.insert(tk.END,'\n')

def save_as_csv():  #保存文件的函数
    with open('Student.csv','w',encoding='utf-8',newline='') as fp:
        wr=writer(fp)
        l4=zip(name,id,score)   #将三个列表合并为一个
        l4=sorted(l4,key=lambda x:int(x[2]),reverse=True)   #按成绩排序
        for item in l4:
            wr.writerow(item)   #将每一条信息写入CSV文件
        tkinter.messagebox.showinfo(title='Success',message='保存成功')     #若保存成功则弹出提示

def read_csv():     #读取之前保存到CSV文件的信息
    try:    #若不存在该文件，则弹出提示
        with open('Student.csv','r',encoding='utf-8',newline='') as fp:
            name.clear()    #清空现有列表的数据
            id.clear()
            score.clear()
            rd=reader(fp)
            for item in rd:     #将CSV文件中所有信息写入列表
                name.append(item[0])
                id.append(item[1])
                score.append(item[2])
            tkinter.messagebox.showinfo(title='Success',message='读取成功')
    except:
        tkinter.messagebox.showinfo(title='Fail',message='文件为空，读取失败')

def open_csv():    #打开之前保存的CSV文件
    try:
        os.startfile('Student.csv')
    except:
        tkinter.messagebox.showinfo(title='Fail',message='打开失败，文件不存在')

#以下为按钮控件，并设置相同长度：25
b=tk.Button(window,text='新增成绩条目',fg='red',command=add_score,width=25)
b2=tk.Button(window,text='查看所有学生成绩信息',command=show_score,width=25)
b3=tk.Button(window,text='从高到低查看学生成绩',command=show_score_sorted,width=25)
b4=tk.Button(window,text='保存到Student.csv文件',command=save_as_csv,width=25)
b5=tk.Button(window,text='读取Student.csv文件中的信息',command=read_csv,width=25)
b6=tk.Button(window,text='打开Student.csv文件',command=open_csv,width=25)
b.pack(pady=10)
b2.pack()
b3.pack()
b4.pack()
b5.pack()
b6.pack()
text1=tk.Text(window,height=20) #创建多行文本框
text1.pack()
window.mainloop()   #开始主循环