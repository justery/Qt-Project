#include "editpropertydialog.h"
#include "ui_EditProperty.h"  //*.ui   根据ui文件名生成ui_*.h

EditPropertyDialog::EditPropertyDialog(QString dialogName,QString tab1Name,QDialog *parent)
    : m_editPropDialogName(dialogName),
      m_editPropTab1Name(tab1Name),
      QDialog(parent),
      ui(new Ui::EditPropertyDialog)
{
    ui->setupUi(this);
    ui->tab->setWindowTitle(dialogName);
    ui->label->setText(tab1Name);
}

EditPropertyDialog::~EditPropertyDialog()
{
    delete ui;
}
