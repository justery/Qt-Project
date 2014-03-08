#ifndef EDITPROPERTYDIALOG_H
#define EDITPROPERTYDIALOG_H

#include <QDialog>

namespace Ui {
class EditPropertyDialog;//即Qt设计师中的对象名
}

class EditPropertyDialog:public QDialog
{
    Q_OBJECT
public:
    EditPropertyDialog(QString dialogName,QString tab1Name,QDialog *parent = 0);
    ~EditPropertyDialog();

    Ui::EditPropertyDialog *ui;

    QString m_editPropDialogName;
    QString m_editPropTab1Name;
};

#endif // EDITPROPERTYDIALOG_H
