#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMdiArea;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:
    void newProject();


private:
    void setupToolBar();
    void setupMenuBar();
    void setupDockWidgets();

    QMdiArea* m_mdiArea;
};

#endif // MAINWINDOW_H
