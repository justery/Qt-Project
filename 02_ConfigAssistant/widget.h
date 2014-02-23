#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTreeWidget;
class QTableWidget;
class QContextMenuEvent;
class QTreeWidgetItem;


/* oriental widget */
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(const QString& name,QWidget *parent = 0);
    QSize sizeHint() const;

    //void contextMenuEvent(QContextMenuEvent* e);
signals:

public slots:
    //void treeItemClicked(QTreeWidgetItem *, int);
    void customContextMenuRequest(const QPoint &);
private:
   QTreeWidget *m_treeWgt;
   QTableWidget *m_tableWgt;
   QString  m_name;
};

//widget for device info
class DeviceInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceInfoWidget(const QString& name,QWidget *parent = 0);
    QSize sizeHint() const;

signals:

public slots:
    void customContextMenuRequest(const QPoint &);

private:
   QTreeWidget      *m_treeWgt;
   QTableWidget     *m_tableWgt;
   QTreeWidgetItem  *m_treeRoot;
   QString          m_name;
};

//widget for group info
class GroupInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GroupInfoWidget(const QString& name,QWidget *parent = 0);
    QSize sizeHint() const;

signals:

public slots:
    void customContextMenuRequest(const QPoint &);

private:
   QTreeWidget *m_treeWgt;
   QTableWidget *m_tableWgt;
   QString  m_name;
};

#endif // WIDGET_H
