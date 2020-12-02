import matplotlib.pyplot as plt
import random
import parser

plt.rcParams['font.family'] = ['simhei']
# random.seed(30)
# 随机生成30位学生的考试成绩
stu_s = [random.randint(40, 100) for i in range(30)]
grade = {'0-49': 0,
         '50-59': 0,
         '60-69': 0,
         '70-79': 0,
         '80-89': 0,
         '90-100': 0}

plt.figure(figsize=(10, 6))
plt.title('学生成绩分段统计图')
plt.ylabel('学生成绩分段人数')
plt.xlabel('分数段')

for i in stu_s:
    if i <= 49:
        s = '0-49'
        grade[s] = grade.get(s, 0) + 1
    elif i <= 59:
        s = '50-59'
        grade[s] = grade.get(s, 0) + 1
    elif i <= 69:
        s = '60-69'
        grade[s] = grade.get(s, 0) + 1
    elif i <= 79:
        s = '70-79'
        grade[s] = grade.get(s, 0) + 1
    elif i <= 89:
        s = '80-89'
        grade[s] = grade.get(s, 0) + 1
    else:
        s = '90-100'
        grade[s] = grade.get(s, 0) + 1

gr1_name = list()
gr1_data = list()
for i in grade:
    gr1_name.append(i)
    gr1_data.append(grade[i])
gr1 = range(len(gr1_name))
plt.xticks(gr1, gr1_name)
plt.bar(gr1_name, gr1_data, 0.6, color='c')
for x, y in zip(gr1_name, gr1_data):
    plt.text(x, y + 0.1, str(y))

plt.show()

parser.add_argument()











