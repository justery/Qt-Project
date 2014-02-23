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

DeviceInfoWidget::DeviceInfoWidget(const QString& name, QWidget *parent) :
    QWidget(parent),m_treeWgt(NULL),m_tableWgt(NULL),m_treeRoot(NULL),m_name(name)
{
    m_treeWgt = new QTreeWidget(this);
    m_treeRoot = new QTreeWidgetItem(QStringList()<<name);//named root with in-arg
    m_treeWgt->addTopLevelItem(m_treeRoot);
    m_treeWgt->setHeaderLabel("device tree view");
    m_treeWgt->setHeaderHidden(true);

    m_treeWgt->setContextMenuPolicy(Qt::CustomContextMenu);//以自定义方式响应鼠标右键

    connect(m_treeWgt, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(customContextMenuRequest(const QPoint &)));

    //connect(m_treeWgt, SIGNAL(itemPressed(QTreeWidgetItem *, int)),
    //        this, SLOT(treeItemClicked(QTreeWidgetItem *, int)));


    for (int i=0; i<1; ++i)
    {
        QTreeWidgetItem * firstNode = new QTreeWidgetItem(QStringList()<<QString("rootFirstNode").sprintf("%d New Area",i+1));
        QTreeWidgetItem * firstNodeChild = new QTreeWidgetItem(QStringList()<<QString("rootFirstNodeChild").sprintf("%d.1 New Line",i+1));
        firstNode->addChild(firstNodeChild );
        m_treeRoot->addChild(firstNode);
    }

    m_treeWgt->expandAll();

    m_tableWgt = new QTableWidget(1,3);
    m_tableWgt->setHorizontalHeaderLabels(QStringList()<<"Address"<<"Name"<<"Description");

    QSplitter * splitter = new QSplitter(this);
    splitter->addWidget(m_treeWgt);
    splitter->addWidget(m_tableWgt);
    splitter->setStretchFactor(1,1);

    splitter->resize(sizeHint());
}

QSize DeviceInfoWidget::sizeHint() const
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();//

    return QSize(clientRect.width()-16,clientRect.height()/2-72);
}

static bool isDescendant(QTreeWidgetItem* item1, QTreeWidgetItem* item2, int &level)
{

    if (item1->childCount()==0)
    {
        return false;
    }

    if (item1->indexOfChild(item2) != -1)
    {
        ++level;
        return true;
    }

    ++level;
    for (int i=0; i<item1->childCount(); ++i)
    {
        if (isDescendant(item1->child(i), item2, level))
        {
            return true;
        }
    }

    return false;
}

void DeviceInfoWidget::customContextMenuRequest(const QPoint & pos)
{
#if 1
    QTreeWidgetItem* item = m_treeWgt->itemAt(pos);
    qDebug()<<m_treeWgt->headerItem()->text(0);
    if(!item)
    {
        return ;
    }

    qDebug()<<"m_treeWgt:"<<m_treeWgt;
    qDebug()<<"m_treeWgt children size:"<<m_treeWgt->children().size();
    qDebug()<<"item:"<<item;
    qDebug()<<"item->childCount:"<<item->childCount();

    qDebug()<<"item->treeWidget():"<<item->treeWidget();
    qDebug()<<"item->parent():"<<item->parent();

    qDebug()<<"------------------------"<<item->childCount();

    qDebug()<<"m_treeRoot contains item?"<<m_treeRoot->indexOfChild(item);
    qDebug()<<"------------------------"<<22;

    QMenu *menu = new QMenu(this);
    if (item == m_treeRoot)
    {// root node, level 0
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
    else if (m_treeRoot->indexOfChild(item) != -1)
    {//level 1, like "New Area"
        QAction *act = new QAction(tr("&Collapse"),this);
        menu->addAction(act);

        act = new QAction(tr("Download..."),this);
        menu->addAction(act);

        act = new QAction(tr("&Add Lines..."),this);
        menu->addAction(act);

        act = new QAction(tr("Add Devices..."),this);
        menu->addAction(act);

        act = new QAction(tr("&Delete"),this);
        menu->addAction(act);

        act = new QAction(tr("&Copy"),this);
        menu->addAction(act);

        act = new QAction(tr("&Properties"),this);
        menu->addAction(act);
    }
    else
    {
        int level = 0;
        if (isDescendant(m_treeRoot, item, level) && level == 2)
        {// level 2
            QAction *act = new QAction(tr("&Expand"),this);
            menu->addAction(act);

            act = new QAction(tr("Expand All"),this);
            menu->addAction(act);

            act = new QAction(tr("&Add Devices..."),this);
            menu->addAction(act);

            act = new QAction(tr("Download..."),this);
            menu->addAction(act);

            act = new QAction(tr("&Delete"),this);
            menu->addAction(act);

            act = new QAction(tr("&Set Current Line"),this);
            menu->addAction(act);

            act = new QAction(tr("&Cut"),this);
            menu->addAction(act);

            act = new QAction(tr("&Copy"),this);
            menu->addAction(act);

            act = new QAction(tr("&Properties"),this);
            menu->addAction(act);
        }
    }

    //qDebug() << pos;
    //qDebug() << mapToGlobal(pos);
    menu->exec(mapToGlobal(pos+QPoint(5,10)));//convert to screen corr-system
    delete menu;
#endif
}



GroupInfoWidget::GroupInfoWidget(const QString& name, QWidget *parent) :
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
                                           QString("").sprintf("Node%d",i+1)));
    }
    m_treeWgt->expandAll();

    static const int groupDeviceTableColomunSize = 4;
    m_tableWgt = new QTableWidget(1, groupDeviceTableColomunSize);
    m_tableWgt->setHorizontalHeaderLabels(QStringList()<<"Address"<<"Name"<<"Description"<<"Pass through Line Coupler");
    m_tableWgt->setColumnWidth(groupDeviceTableColomunSize-1,180);

    QSplitter * splitter = new QSplitter(this);
    splitter->addWidget(m_treeWgt);
    splitter->addWidget(m_tableWgt);
    splitter->setStretchFactor(1,1);

    splitter->resize(sizeHint());
}

QSize GroupInfoWidget::sizeHint() const
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();//

    return QSize(clientRect.width()-16,clientRect.height()/2-72);
}


void GroupInfoWidget::customContextMenuRequest(const QPoint & pos)
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


    qDebug() << pos;
    qDebug() << mapToGlobal(pos);
    menu->exec(mapToGlobal(pos+QPoint(5,26)));
    delete menu;
}


#if 1
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


//void Widget::contextMenuEvent(QContextMenuEvent* e)
//{
//    QMenu *menu = new QMenu();


//    QAction *act = new QAction(tr("&Collapse"),this);
//    menu->addAction(act);

//    act = new QAction(tr("&Add Areas..."),this);
//    menu->addAction(act);

//    act = new QAction(tr("&Add Lines..."),this);
//    menu->addAction(act);

//    act = new QAction(tr("&Add Devices..."),this);
//    menu->addAction(act);

//    act = new QAction(tr("&Copy"),this);
//    menu->addAction(act);

//    act = new QAction(tr("&Properties"),this);
//    menu->addAction(act);

//    menu->addSeparator();

//    menu->addSeparator();

//    //menu->addAction(Act_Maxsize);

//    menu->addSeparator();

//    menu->addSeparator();

//    //menu->addAction(Act_Normal);

//    menu->addSeparator();

//    menu->addSeparator();

//    menu->exec(e->globalPos());

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
