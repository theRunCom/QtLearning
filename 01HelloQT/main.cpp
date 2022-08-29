// 对于每个Qt类，都有一个与该类同名且大写的头文件，在这个头文件中包括了对该类的定义
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    // QApplication构造函数创建需要两个参数，因为Qt支持它自己的一些命令行参数
    QApplication a(argc, argv);
    /*QLabel* label = new QLabel("Hello Qt!");*/
    QLabel* label = new QLabel("<h2><i>Hello</i> <font color=red>Qt!</font></h2>");
    // Qt的任意部件都可以用作窗口
    // 先进行设置，然后再显示他们，从而避免了窗口部件的闪烁现象
    label->show();
    // 程序进入事件循环状态，这是一种等待模式，程序会等候用户的动作
    return a.exec();
}
