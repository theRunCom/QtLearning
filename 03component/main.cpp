#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QWidget* window = new QWidget;
    window->setWindowTitle("Enter Your Age");

    QSpinBox* spinBox = new QSpinBox;
    QSlider* slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    // 函数调用会在该窗口安装该布局管理器
    // QSpinBox和QSlider会自动“重定义父对象”，它们会成为这个安装了布局的窗口部件的子对象。
    // 也正是基于这种原因，当创建一个需要放进某个布局中的窗口部件时，就没有必要为其显式地指定父对象了。
    window->setLayout(layout);

    // 布局会自动设置部件的位置和大小
    window->show();

    return a.exec();
}
