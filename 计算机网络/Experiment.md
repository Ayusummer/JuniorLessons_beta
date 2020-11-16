# 实验4 跨交换机VLAN配置实验
## 实验目标
- 进一步熟悉VLAN配置的方法;
- 掌握通过建立交换路径进行跨交换VLAN的配置方法

---
## 实验内容
- pic
- 创建VLAN
- VLAN指定端口
- 建立交换路径

## CLI配置代码
- 两个VLAN
- SZYF0
```
enable 
conf t
hostname SZYF0
exit
vlan database
vlan 2 name vlan2
vlan 3 name vlan3
exit
conf t
int f0/1
switchport access vlan 2
int f0/2
switchport access vlan 3
int f0/3
switchport access vlan 2
int f0/4
switchport access vlan 3
exit
exit
sh vlan brief
```
- SZYF1
```
enable 
conf t
hostname SZYF1
exit
vlan database
vlan 2 name vlan2
vlan 3 name vlan3
exit
conf t
int f0/1
switchport access vlan 2
int f0/2
switchport access vlan 3
int f0/3
switchport access vlan 2
int f0/4
switchport access vlan 3
exit
exit
sh vlan brief
```
- 配置完成后去PCZYF0测试ping
- pic
- 再去PCZYF1测试ping
- pic



