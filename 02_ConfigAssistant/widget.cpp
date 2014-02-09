#include "widget.h"
//test git
#include <QTreeWidget>
#include <QTableWidget>

#include <QDebug>

#include <QSplitter>
#include <QDesktopWidget>
#include <QApplication>
#include <QMenu>
#include <QContextMenuEvent>
#include <QTreeWidgetItem>

Widget::Widget(const QString& name, QWidget *parent) :
    QWidget(parent),m_treeWgt(NULL),m_tableWgt(NULL),m_name(name)
{
    m_treeWgt = new QTreeWidget(this);
    QTreeWidgetItem* root = new QTreeWidgetItem(QStringList()<<name);
    m_treeWgt->addTopLevelItem(root);
    m_treeWgt->setHeaderLabel("");

    m_treeWgt->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(m_treeWgt, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(customContextMenuRequest(const QPoint &)));

    //connect(m_treeWgt, SIGNAL(itemPressed(QTreeWidgetItem *, int)),
    //        this, SLOT(treeItemClicked(QTreeWidgetItem *, int)));

    //itemPressed
    for (int i=0; i<10; ++i)
    {
        root->addChild(new QTreeWidgetItem(QStringList()<<
                                           QString("node").sprintf("Node%d",i+1)));
    }
    m_treeWgt->expandAll();

    m_tableWgt = new QTableWidget(1,4);
    m_tableWgt->setHorizontalHeaderLabels(QStringList()<<"ID"<<"Name"<<"Address"<<"Tip");

    QSplitter * splitter = new QSplitter(this);
    splitter->addWidget(m_treeWgt);
    splitter->addWidget(m_tableWgt);
    splitter->setStretchFactor(1,1);

    splitter->resize(sizeHint());
}

QSize Widget::sizeHint() const
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();//

    return QSize(clientRect.width()-16,clientRect.height()/2-72);
}

#if 0
void Widget::contextMenuEvent(QContextMenuEvent* e)
{
    QMenu *menu = new QMenu();


    QAction *act = new QAction(tr("&Collapse"),this);
    menu->addAction(act);

    act = new QAction(tr("&Add Areas..."),this);
    menu->addAction(act);

    act = new QAction(tr("&Add Lines..."),this);
    menu->addAction(act);

    act = new QAction(tr("&Add Devices..."),this);
    menu->addAction(act);

    act = new QAction(tr("&Copy"),this);
    menu->addAction(act);

    act = new QAction(tr("&Properties"),this);
    menu->addAction(act);

    menu->addSeparator();

    menu->addSeparator();

    //menu->addAction(Act_Maxsize);

    menu->addSeparator();

    menu->addSeparator();

    //menu->addAction(Act_Normal);

    menu->addSeparator();

    menu->addSeparator();

    menu->exec(e->globalPos());

    delete menu;

}
#endif

//void Widget::treeItemClicked(QTreeWidgetItem * treeItem, int col)
//{
//    qDebug() << treeItem->text(0);

//    QMenu *menu = new QMenu();
//    if (NULL == treeItem->parent())
//    {
//        QAction *act = new QAction(tr("&Collapse"),this);
//        menu->addAction(act);

//        act = new QAction(tr("&Add Areas..."),this);
//        menu->addAction(act);

//        act = new QAction(tr("&Add Lines..."),this);
//        menu->addAction(act);

//        act = new QAction(tr("&Add Devices..."),this);
//        menu->addAction(act);

//        act = new QAction(tr("&Copy"),this);
//        menu->addAction(act);

//        act = new QAction(tr("&Properties"),this);
//        menu->addAction(act);
//    }

//    menu->exec(cursor().pos());
//    delete menu;
//}

void Widget::customContextMenuRequest(const QPoint & pos)
{
    QTreeWidgetItem* item = m_treeWgt->itemAt(pos);
    if(NULL == item)
    {
        return ;
    }

    QMenu *menu = new QMenu(this);
    if (NULL == item->parent())
    {
        QAction *act = new QAction(tr("&Collapse"),this);
        menu->addAction(act);

        act = new QAction(tr("&Add Areas..."),this);
        menu->addAction(act);

        act = new QAction(tr("&Add Lines..."),this);
        menu->addAction(act);

        act = new QAction(tr("&Add Devices..."),this);
        menu->addAction(act);

        act = new QAction(tr("&Copy"),this);
        menu->addAction(act);

        act = new QAction(tr("&Properties"),this);
        menu->addAction(act);
    }
    else if (item->text(0)=="")
    {
        //
    }

//    QPoint	mapFrom(const QWidget * parent, const QPoint & pos) const
//    QPoint	mapFromGlobal(const QPoint & pos) const
//    QPoint	mapFromParent(const QPoint & pos) const
//    QPoint	mapTo(const QWidget * parent, const QPoint & pos) const
//    QPoint	mapToGlobal(const QPoint & pos) const
//    QPoint	mapToParent(const QPoint & pos) const

    qDebug() << pos;
    qDebug() << mapToGlobal(pos);
    menu->exec(mapToGlobal(pos+QPoint(5,26)));
    delete menu;
}
