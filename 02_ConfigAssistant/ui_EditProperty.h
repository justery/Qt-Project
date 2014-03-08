/********************************************************************************
** Form generated from reading UI file 'EditProperty.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROPERTY_H
#define UI_EDITPROPERTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditPropertyDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QTextEdit *textEdit;
    QLabel *label_4;
    QComboBox *comboBox;
    QWidget *tab_2;
    QCheckBox *checkBox;
    QTextEdit *textEdit_2;
    QLabel *label_5;
    QComboBox *comboBox_2;

    void setupUi(QDialog *EditPropertyDialog)
    {
        if (EditPropertyDialog->objectName().isEmpty())
            EditPropertyDialog->setObjectName(QStringLiteral("EditPropertyDialog"));
        EditPropertyDialog->setEnabled(true);
        EditPropertyDialog->resize(344, 234);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditPropertyDialog->sizePolicy().hasHeightForWidth());
        EditPropertyDialog->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(EditPropertyDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        tabWidget = new QTabWidget(EditPropertyDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 311, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        textEdit = new QTextEdit(formLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy2);

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setEditable(false);
        comboBox->setModelColumn(0);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 140, 185, 16));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(11, 11, 301, 121));
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 170, 111, 16));
        comboBox_2 = new QComboBox(tab_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(138, 170, 81, 20));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy3);
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(EditPropertyDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditPropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *EditPropertyDialog)
    {
        EditPropertyDialog->setWindowTitle(QApplication::translate("EditPropertyDialog", "Dialog", 0));
        label->setText(QApplication::translate("EditPropertyDialog", "Address:", 0));
        label_2->setText(QApplication::translate("EditPropertyDialog", "Name:", 0));
        label_3->setText(QApplication::translate("EditPropertyDialog", "Description:", 0));
        label_4->setText(QApplication::translate("EditPropertyDialog", "Medium:", 0));
        comboBox->setCurrentText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EditPropertyDialog", "Tab 1", 0));
        checkBox->setText(QApplication::translate("EditPropertyDialog", "Rich text(bold,italic etc.)", 0));
        label_5->setText(QApplication::translate("EditPropertyDialog", "Completion Status:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("EditPropertyDialog", "Comment", 0));
    } // retranslateUi

};

namespace Ui {
    class EditPropertyDialog: public Ui_EditPropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROPERTY_H
