import numpy as np
from matplotlib import pyplot as plt
import os

file_path_arr = os.path.abspath(os.path.join(os.path.dirname(__file__), './res/populations.npz'))

dataframe = np.load(file_path_arr, encoding="bytes", allow_pickle=True)
# print(dataframe.files)#查看关键字
# print(dataframe['feature_names'])查看数据特征
# print(dataframe['data'])#查看数据
year = np.linspace(2015, 1996, 20).reshape(-1, 1)               # 自主生成年份数组而没有获取数据第0列
year_population = dataframe['data'][0:20, 1].reshape(-1, 1)
man_population = dataframe['data'][0:20, 2].reshape(-1, 1)
woman_population = dataframe['data'][0:20, 3].reshape(-1, 1)
city_population = dataframe['data'][0:20, 4].reshape(-1, 1)
country_population = dataframe['data'][0:20, 5].reshape(-1, 1)  # 重构数组为?行1列,-1使得行数会自动计算

plt.figure(figsize=(4, 4), dpi=120)
plt.style.use('tableau-colorblind10')
plt.figure(1)

plt.subplot(211)
plt.title('人口与年份折线图')
plt.ylabel('年份')
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

plt.plot(year, year_population, label='年末总人口')
plt.plot(year, man_population, label='男性人口')
plt.plot(year, woman_population, label='女性人口')
plt.plot(year, city_population, label='城镇人口')
plt.plot(year, country_population, label='乡村人口')
# plt.legend()

plt.subplot(212)
plt.title('人口与年份散点图')
plt.ylabel('年份')

plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

plt.scatter(year, year_population, alpha=0.6, marker='.', label='年末总人口')
plt.scatter(year, man_population, alpha=0.6, marker='v', label='男性人口')
plt.scatter(year, woman_population, alpha=0.6, marker='<', label='女性人口')
plt.scatter(year, city_population, alpha=0.6, marker='>', label='城镇人口')
plt.scatter(year, country_population, alpha=0.6, marker='1', label='乡村人口')
# plt.legend()
plt.show()

plt.xticks