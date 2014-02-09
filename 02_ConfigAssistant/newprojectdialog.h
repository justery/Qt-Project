#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjDialog;//根对象名字决定
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewProjectDialog(QDialog *parent = 0);

    ~NewProjectDialog();

    int exec();


    Ui::NewProjDialog *ui;
private:
    //Ui::Dialog *ui;
    //QString m_name;
};

//single member mode

#endif // NEWPROJECTDIALOG_H
