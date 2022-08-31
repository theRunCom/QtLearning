# QtLearning
C++ Qt学习例子

## 《C++ GUI Qt4 编程（第二版）》读书笔记
### QT基础
#### 1）QT入门
- 简单的HelloQT例子：[01HelloQT](https://github.com/theRunCom/QtLearning/tree/main/01HelloQT)
- 信号与槽的初应用：[02Connect](https://github.com/theRunCom/QtLearning/tree/main/02Connect)
- Qt组件的使用：[03component](https://github.com/theRunCom/QtLearning/tree/main/03component)
#### 2）创建对话框
基本步骤：

1. 创建并初始化子窗口部件；
2. 把子窗口部件放到布局中；
3. 设置Tab建顺序；
4. 建立信号-槽之间的连接；
5. 实现对话框中的自定义槽。
- 一个查找对话框：[04BuildDialog](https://github.com/theRunCom/QtLearning/tree/main/04BuidDialog)
-> 效果图：[查找对话框](https://github.com/theRunCom/QtLearning/blob/main/images/04.png)

- 可视化界面设计Go To Cell的对话框：
-> 效果图：[Go To Cell对话框](https://github.com/theRunCom/QtLearning/blob/main/images/05.png)
  步骤：
  
    1）使用文本标签Label，将它的text属性设置成“&Cell Location：”；
    
    2）使用行编辑器lineEdit；
    
    3）设置Ok、Cancel两个按钮，第一个按钮，将objectName属性设置为"okButoon"，将它的enabled属性设置成"false"，text属性设置为"OK"，default属性设置为"true"，第二个按钮objectName属性设置成"cancelButton"，text属性设置成"Cancel"；
    
    4）将整个窗口的objectName属性设置成"GoToCellDialog"，并将WindowTitle属性设置成"Go To Cell"；
    
    5）单击Edit->Edit Buddies进入允许设置窗口部件伙伴的特殊模式，单击标签将红色箭头指向行编辑器；
    
    6）同时选中标签与行编辑器，单击窗口->水平布局，同理，两个按钮；
    
    7）单击窗口的空白，取消对所有已选项的选择，然后单击窗口->垂直布局；
    
    8）单击Form->Adjust Size，重新把窗体的大小定义为最佳形式；
    
    9）设置Tab顺序，单击Edit->Edit Tab Order；
    
    10）另存为gotocelldialog.ui文件。
#### 3）创建主窗口
#### 4）实现应用程序的的功能
#### 5）创建自定义窗口部件
