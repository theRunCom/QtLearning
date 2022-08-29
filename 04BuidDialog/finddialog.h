#pragma once

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog {
	// 对于所有定义了信号和槽的类，在类定义开始处的Q_OBJECT宏都是必需的
	Q_OBJECT
public:
	// parent参数指定了它的父窗口部件，该参数的默认值是一个空指针，意味着该对话框没有父对象
	FindDialog(QWidget* parent = 0);
signals:
	// Qt::CaseSensitivity是一个枚举类型，它有Qt::CaseSensitive和Qt::CaseInsensitive
	void findNext(const QString& str, Qt::CaseSensitivity cs);
	void findPrevious(const QString& str, Qt::CaseSensitivity cs);
private slots:
	void findClicked();
	void enableFindButton(const QString& text);
private:
	// 对于这些私有变量声明，我们使用他们的前置类声明。
	// 这是可行的，因为他们是指针，而且没有必要在头文件中就去访问他们，因而编译程序就无须这些类的完整定义。
	// 这样可以使得编译更快一点
	QLabel* label;
	QLineEdit* lineEdit;
	QCheckBox* caseCheckBox;
	QCheckBox* backwardCheckBox;
	QPushButton* findButton;
	QPushButton* closeButton;
};