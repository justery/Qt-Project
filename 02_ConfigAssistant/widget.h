#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTreeWidget;
class QTableWidget;
class QContextMenuEvent;
class QTreeWidgetItem;

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

#endif // WIDGET_H
