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
    // �������û��ڸô��ڰ�װ�ò��ֹ�����
    // QSpinBox��QSlider���Զ����ض��常���󡱣����ǻ��Ϊ�����װ�˲��ֵĴ��ڲ������Ӷ���
    // Ҳ���ǻ�������ԭ�򣬵�����һ����Ҫ�Ž�ĳ�������еĴ��ڲ���ʱ����û�б�ҪΪ����ʽ��ָ���������ˡ�
    window->setLayout(layout);

    // ���ֻ��Զ����ò�����λ�úʹ�С
    window->show();

    return a.exec();
}
