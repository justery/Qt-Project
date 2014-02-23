#include "mainwindow.h"
#include "widget.h"
#include "newprojectdialog.h"
#include "ui_NewProjectDialog.h"

#include <QDebug>
#include <QMenuBar>
#include <QDockWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QMdiArea>
#include <QApplication>
#include <QTreeView>
#include <QTableView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QLabel>
#include <QSizePolicy>
#include <QWidget>
#include <QMdiSubWindow>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_mdiArea(NULL)
{
    m_mdiArea = new QMdiArea;
    setCentralWidget(m_mdiArea);

#if 0
    QStandardItemModel *model = new QStandardItemModel;
        QTableView* pTableView = new QTableView;
        model->setColumnCount(5);    // 设置列数

        //设置列标题
        model->setHeaderData(0,Qt::Horizontal,"ID");
        model->setHeaderData(1,Qt::Horizontal,"NAME");
        model->setHeaderData(2,Qt::Horizontal,"AGE");
        //for (int i = 0; i < 2; i++)
        //{
        //    model->setItem(i,0,new QStandardItem(QString("%1").arg(i+1)) );
        //    model->setItem(i,1,new QStandardItem(QString("Aaron%1").arg(i)));
        //}


        /*
        //相同效果
        QStandardItem *item;
        QList<QStandardItem *> items;
        for (int i = 0; i < 2; i++)
        {
            items.clear();
            item = new QStandardItem("Aaron");
            //item->setCheckable(true);
            items.push_back(item);
            item = new QStandardItem("12.21");
            items.push_back(item);
            model->appendRow(items);
        }
        */

        pTableView->setModel(model);

        //隐藏左边那列
        //pTableView->verticalHeader()->hide();

        //设置某列隐藏
        //pTableView->setColumnHidden(0,true);


        //列宽
        pTableView->setColumnWidth(0,60);

        //整行选择
        pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
#endif

    setWindowTitle("Config Assistant");
    setupMenuBar();
    setupToolBar();


    statusBar()->addWidget(new QLabel("status on"));
    setupDockWidgets();

}

MainWindow::~MainWindow()
{

}

void MainWindow::setupMenuBar()
{
    //## Menu:File
    QMenu *menu = menuBar()->addMenu(tr("&File"));
    //connect(menu, SIGNAL(triggered()),this,SLOT(close()));

    QAction* act = new QAction(tr("&New Project"),this);
    act->setShortcut(tr("Ctrl+N"));
    connect(act, SIGNAL(triggered()),this, SLOT(newProject()));
    menu->addAction(act);

    act = new QAction(tr("&Open"),this);
    act->setShortcut(tr("Ctrl+O"));
    //connect(act, SIGNAL(triggered()),this, SLOT(openFile()));
    menu->addAction(act);

    act = new QAction(tr("&Recent Files..."),this);
    //connect(act, SIGNAL(triggered()),this, SLOT(openRecentFile()));
    menu->addAction(act);

    act = new QAction(tr("&Exit"),this);
    act->setShortcut(tr("Ctrl+X"));
    connect(act, SIGNAL(triggered()),qApp, SLOT(quit()));
    menu->addAction(act);

    //## Menu:Edit
    menuBar()->addSeparator();

    menu = menuBar()->addMenu(tr("&Edit"));

    act = new QAction(tr("&Undo"),this);
    menu->addAction(act);

    act = new QAction(tr("&Redo"),this);
    menu->addAction(act);

    //## Menu:Option
    menuBar()->addSeparator();

    menu = menuBar()->addMenu(tr("&Option"));

    act = menu->addAction(tr("Setting1"));
    menu->addAction(act);

    act = menu->addAction(tr("Setting2"));
    menu->addAction(act);
}

void MainWindow::setupToolBar()
{
}

void MainWindow::setupDockWidgets()
{

//    case Qt::RightDockWidgetArea:
//    case Qt::TopDockWidgetArea:
//    case Qt::BottomDockWidgetArea:

    //可停靠控件的实现方法
    /*
    QDockWidget* dw = new QDockWidget;
    dw->setWindowTitle("File Tree");
    dw->setWidget(new QLineEdit);
    dw->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);//只允许出现在左右侧
    addDockWidget(Qt::LeftDockWidgetArea, dw);

    dw = new QDockWidget;
    dw->setWindowTitle("Debug Info");
    dw->setWidget(new QTextEdit);
    dw->setAllowedAreas(Qt::BottomDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea,dw);
    */
}

void MainWindow::newProject()
{
    NewProjectDialog dialog;

    if (!dialog.exec())
        return ;

    qDebug()<<"lineEdit text:"<<dialog.ui->lineEdit->text();
    qDebug()<<"comboBox currentText:"<<dialog.ui->comboBox->currentText();
    qDebug()<<"checkBox isChecked:"<<dialog.ui->checkBox->isChecked();

    //generate two tree
    DeviceInfoWidget * devInfo = new DeviceInfoWidget(dialog.ui->lineEdit->text());
    GroupInfoWidget * groupInfo = new GroupInfoWidget("Maingroups");

    QSizePolicy sp;
    sp.setHorizontalStretch(1);
    sp.setVerticalStretch(1);

    devInfo->setSizePolicy(sp);
    groupInfo->setSizePolicy(sp);

    QMdiSubWindow* devInfoSubWin = m_mdiArea->addSubWindow(devInfo);
    QMdiSubWindow* groupInfoSubWin = m_mdiArea->addSubWindow(groupInfo);
    devInfoSubWin->setAttribute(Qt::WA_DeleteOnClose);
    groupInfoSubWin->setAttribute(Qt::WA_DeleteOnClose);

    groupInfoSubWin->setGeometry(0,396,1439,396);
    devInfoSubWin->show();
    groupInfoSubWin->show();

    QJsonObject jsonObject;
    jsonObject["name"] = 1;
    qDebug()<<"jsonObject content:"
           <<QJsonDocument(jsonObject).toJson();
}

//QTableView 用法
#if 0
QStandardItemModel *model = new QStandardItemModel;

    QTableView* pTableView = new QTableView;
    model->setColumnCount(2);    // 设置列数

    //设置列标题
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"NAME");
    //for (int i = 0; i < 2; i++)
    //{
    //    model->setItem(i,0,new QStandardItem(QString("%1").arg(i+1)) );
    //    model->setItem(i,1,new QStandardItem(QString("Aaron%1").arg(i)));
    //}


    /*
    //相同效果
    QStandardItem *item;
    QList<QStandardItem *> items;
    for (int i = 0; i < 2; i++)
    {
        items.clear();
        item = new QStandardItem("Aaron");
        //item->setCheckable(true);
        items.push_back(item);
        item = new QStandardItem("12.21");
        items.push_back(item);
        model->appendRow(items);
    }
    */

    pTableView->setModel(model);

    //隐藏左边那列
    pTableView->verticalHeader()->hide();

    //设置某列隐藏
    //pTableView->setColumnHidden(0,true);


    //列宽
    pTableView->setColumnWidth(0,60);

    //整行选择
    pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    pTableView->show();
#endif

//QListView用法
#if 0
    QListView* listView = new QListView(this);
    QStandardItemModel* standardItemModel = new QStandardItemModel(this);

        QStringList strList;
        strList.append("string1");
        strList.append("string2");
        strList.append("string3");
        strList.append("string4");
        strList.append("string5");
        strList.append("string6");
        strList.append("string7");
        strList << "string8";
        strList += "string9";
        int nCount = strList.size();
        for(int i = 0; i < nCount; i++)
        {
            QString string = static_cast<QString>(strList.at(i));
            QStandardItem *item = new QStandardItem(string);
            if(i % 2 == 1)
            {
                QLinearGradient linearGrad(QPointF(0, 0), QPointF(200,200));
                linearGrad.setColorAt(0, Qt::darkGreen);
                linearGrad.setColorAt(1, Qt::yellow);
                QBrush brush(linearGrad);
                item->setBackground(brush);
            }
            standardItemModel->appendRow(item);

            standardItemModel->appendColumn();
        }
        listView->setModel(standardItemModel);
        listView->setFixedSize(200,300);
        connect(listView,SIGNAL(clicked(QModelIndex)),this,SLOT(itemClicked(QModelIndex)));

#endif
