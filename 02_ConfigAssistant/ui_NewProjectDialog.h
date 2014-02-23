/********************************************************************************
** Form generated from reading UI file 'NewProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewProjDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;

    void setupUi(QDialog *NewProjDialog)
    {
        if (NewProjDialog->objectName().isEmpty())
            NewProjDialog->setObjectName(QStringLiteral("NewProjDialog"));
        NewProjDialog->resize(291, 111);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewProjDialog->sizePolicy().hasHeightForWidth());
        NewProjDialog->setSizePolicy(sizePolicy);
        NewProjDialog->setMinimumSize(QSize(291, 111));
        NewProjDialog->setMaximumSize(QSize(291, 111));
        NewProjDialog->setBaseSize(QSize(0, 0));
        NewProjDialog->setSizeGripEnabled(false);
        layoutWidget = new QWidget(NewProjDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 291, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 0, 10, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        buttonBox_2 = new QDialogButtonBox(layoutWidget);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setOrientation(Qt::Vertical);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox_2, 0, 2, 3, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setContextMenuPolicy(Qt::CustomContextMenu);
        comboBox->setEditable(false);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        comboBox->setModelColumn(0);

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 2, 0, 1, 2);


        retranslateUi(NewProjDialog);

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(NewProjDialog);
    } // setupUi

    void retranslateUi(QDialog *NewProjDialog)
    {
        NewProjDialog->setWindowTitle(QApplication::translate("NewProjDialog", "Add New Project", 0));
        label->setText(QApplication::translate("NewProjDialog", "Name:", 0));
        label_2->setText(QApplication::translate("NewProjDialog", "Medium:", 0));
#ifndef QT_NO_ACCESSIBILITY
        comboBox->setAccessibleName(QApplication::translate("NewProjDialog", "<html><head/><body><p>ddd</p><p>bbb</p></body></html>", 0));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        comboBox->setAccessibleDescription(QApplication::translate("NewProjDialog", "<html><head/><body><p>xxx</p><p>yyyy</p></body></html>", 0));
#endif // QT_NO_ACCESSIBILITY
        comboBox->setCurrentText(QString());
        checkBox->setText(QApplication::translate("NewProjDialog", "Create Line 1.1", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProjDialog: public Ui_NewProjDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
