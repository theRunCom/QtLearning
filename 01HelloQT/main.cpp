// ����ÿ��Qt�࣬����һ�������ͬ���Ҵ�д��ͷ�ļ��������ͷ�ļ��а����˶Ը���Ķ���
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    // QApplication���캯��������Ҫ������������ΪQt֧�����Լ���һЩ�����в���
    QApplication a(argc, argv);
    QLabel* label = new QLabel("Hello Qt!");
    // Qt�����ⲿ����������������
    // �Ƚ������ã�Ȼ������ʾ���ǣ��Ӷ������˴��ڲ�������˸����
    label->show();
    // ��������¼�ѭ��״̬������һ�ֵȴ�ģʽ�������Ⱥ��û��Ķ���
    return a.exec();
}
