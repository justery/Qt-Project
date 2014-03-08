#include "newprojectdialog.h"
#include "ui_NewProjectDialog.h"

NewProjectDialog::NewProjectDialog(QDialog *parent)
    : QDialog(parent),
      ui(new Ui::NewProjDialog)
{
    ui->setupUi(this);
    ui->comboBox->insertItem(0,"TP");
    ui->comboBox->insertItem(1,"PL");
    connect(ui->buttonBox_2, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox_2, SIGNAL(rejected()), this, SLOT(reject()));
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

int NewProjectDialog::exec()
{
    return QDialog::exec();
}
