#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>

#include "finddialog.h"

// 把parent参数传递给基类的构造函数
FindDialog::FindDialog(QWidget* parent) : QDialog(parent) {
	// tr()函数是将字符串翻译成其他语言的标记
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox(tr("Match &case"));
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	findButton = new QPushButton(tr("&Find"));
	// 默认按钮就是当用户按下Enter键时能够按下对应的按钮
	findButton->setDefault(true);
	// 禁用了该按钮，通常显示为灰色，并且不能和用户发生交互操作
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));
	// 由于QObject是FindDialog的父对象之一，所以可以省略connect（）函数前面的QObject::前缀
	connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout* topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout* leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout* rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked() {
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
	if (backwardCheckBox->isChecked()) {
		emit findPrevious(text, cs);
	}
	else {
		emit findNext(text, cs);
	}
}

void FindDialog::enableFindButton(const QString& text) {
	findButton->setEnabled(!text.isEmpty());
}