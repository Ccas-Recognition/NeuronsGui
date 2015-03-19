#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    createContextMenu();
    createToolbars();
    createStatusBar();
}

void MainWindow::createActions()
{
    // New
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create New Project"));
    newAction->setIcon(QIcon(":/images/new.png"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    // Save
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save your work"));
    saveAction->setIcon(QIcon(":/images/save.png"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    // Detect
    detectAction = new QAction(tr("&Detect"), this);
    detectAction->setStatusTip(tr("Detect neurons on image"));
    detectAction->setIcon(QIcon(":/images/detection.png"));

    // Select
    selectAction = new QAction(tr("Select"), this);
    selectAction->setStatusTip(tr("Select area to compute"));
    selectAction->setIcon(QIcon(":/images/select_all.png"));

    // ChangeView
    changeViewAction = new QAction(tr("Change view"), this);
    changeViewAction->setStatusTip(tr("Change view in image area"));
    changeViewAction->setIcon(QIcon(":/images/change_view.png"));

    // Exit
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    exitAction->setIcon(QIcon(":/images/exit.png"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    // Help
    helpAction = new QAction(tr("&Help"), this);
    helpAction->setStatusTip(tr("Help about project"));
    helpAction->setIcon(QIcon(":/images/help.png"));
    connect(helpAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    // About Qt
    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show Qt About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


void MainWindow::createMenus()
{
    menuBar()->setNativeMenuBar(false);

    // File Menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    // ---------
    fileMenu->addAction(exitAction);

    // Edit Menu
    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(detectAction);
    editMenu->addAction(selectAction);
    editMenu->addAction(changeViewAction);
}

void MainWindow::createContextMenu()
{

}

void MainWindow::createToolbars()
{
    // File Toolbar
    fileToolbar = addToolBar(tr("&File"));
    fileToolbar->addAction(newAction);
    fileToolbar->addAction(saveAction);

    // Separator
    // ---------

    // Service Toolbar
    serviceToolbar = addToolBar(tr("Edit"));
    serviceToolbar->addAction(detectAction);
    serviceToolbar->addAction(selectAction);
    serviceToolbar->addAction(changeViewAction);

    // Separator
    // ---------

    // Help
    helpToolbar = addToolBar(tr("&Help"));
    helpToolbar->addAction(helpAction);
    helpToolbar->addAction(exitAction);
}

// Managing States
void MainWindow::newFile()
{

}


// save
bool MainWindow::save()
{

}

bool MainWindow::saveAs()
{

}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    statusBar()->addWidget(locationLabel);
    updateStatusBar(tr(""));
}

void MainWindow::updateStatusBar(const QString s) {
    locationLabel->setText(s);
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "NeuronsGui",
                                                                    tr("Are you sure?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

MainWindow::~MainWindow()
{

}
