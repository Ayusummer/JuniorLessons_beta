# 定义背包类
class BackSack():
    #类的初始化
    def __init__(self,capacity):    
        self.capacity = capacity    #背包最大容量（重量）
        self.current_weight = 0     #背包当前重量
        self.best_value = 0         #背包可容纳货物的最大价值，最优值
        self.current_value=0        #背包内当前已装货物的价值

    #遍历解空间寻找最优值，i:当前搜索的深度
    def backTrack(self,i):  
        global length, weight, value, goods #全局变量       
        if (i>length):   
            if self.current_value>self.best_value: #更新最优值
                self.best_value=self.current_value
                self.current_capacity=self.current_weight#当前最优解下的背包重量
                self.bestgoods = goods[:5]
                print ('当前最优解:',self.bestgoods)#输出当前的最优解，最后一次输出即是最终的最优解
            return
        if self.current_weight+weight[i]<=self.capacity:#进入左子树，即选取goods[i]放入背包
            goods[i]=1
            self.current_weight=self.current_weight+weight[i]
            self.current_value=self.current_value+value[i]
            self.backTrack(i+1)
            self.current_value=self.current_value-value[i]#进入右子树，即舍弃goods[i]，不放入背包
            self.current_weight=self.current_weight-weight[i]
            goods[i]=0
        self.backTrack(i+1)

def main():
    global length,weight,value,goods #全局变量，分别表示货物数目，货物的重量数组，价值数组，货物的选取即0-1值
    #current_weight = 0
    #best_value=0
    #current_value=0
    #capacity=10
    weight=[2,2,6,5,4]
    value=[6,3,5,4,6]
    goods=[0,0,0,0,0]
    length=len(weight)-1
    backsack=BackSack(10)
    backsack.backTrack(0)
    print(backsack.best_value,backsack.current_capacity) #输出最优值和背包内物品的总重量
    print(backsack.bestgoods) #输出最优解

main()