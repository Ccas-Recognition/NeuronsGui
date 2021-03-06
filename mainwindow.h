#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void newFile();
    bool save();
    bool saveAs();
    /*void process();*/
private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolbars();
    void createStatusBar();
    void updateStatusBar(const QString);

    // Runtime classes

    // Labels
    QLabel *locationLabel;

    // Menus
    QMenu *fileMenu;
    QMenu *editMenu;

    // Toolbars
    QToolBar *fileToolbar;
    QToolBar *serviceToolbar;
    QToolBar *helpToolbar;

    // Actions
    QAction *newAction;
    QAction *saveAction;
    QAction *helpAction;
    QAction *detectAction;
    QAction *selectAction;
    QAction *changeViewAction;
    QAction *exitAction;
    QAction *aboutQtAction;
};

#endif // MAINWINDOW_H
