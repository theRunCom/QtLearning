#pragma once

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog {
	// �������ж������źźͲ۵��࣬���ඨ�忪ʼ����Q_OBJECT�궼�Ǳ����
	Q_OBJECT
public:
	// parent����ָ�������ĸ����ڲ������ò�����Ĭ��ֵ��һ����ָ�룬��ζ�ŸöԻ���û�и�����
	FindDialog(QWidget* parent = 0);
signals:
	// Qt::CaseSensitivity��һ��ö�����ͣ�����Qt::CaseSensitive��Qt::CaseInsensitive
	void findNext(const QString& str, Qt::CaseSensitivity cs);
	void findPrevious(const QString& str, Qt::CaseSensitivity cs);
private slots:
	void findClicked();
	void enableFindButton(const QString& text);
private:
	// ������Щ˽�б�������������ʹ�����ǵ�ǰ����������
	// ���ǿ��еģ���Ϊ������ָ�룬����û�б�Ҫ��ͷ�ļ��о�ȥ�������ǣ������������������Щ����������塣
	// ��������ʹ�ñ������һ��
	QLabel* label;
	QLineEdit* lineEdit;
	QCheckBox* caseCheckBox;
	QCheckBox* backwardCheckBox;
	QPushButton* findButton;
	QPushButton* closeButton;
};