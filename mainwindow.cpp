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
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create New Project"));
    newAction->setIcon(QIcon(":/images/new.png"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show Qt About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


void MainWindow::createMenus()
{
    menuBar()->setNativeMenuBar(false);

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{

}

void MainWindow::createToolbars()
{
    fileToolbar = addToolBar(tr("&File"));
    fileToolbar->addAction(newAction);
}

void MainWindow::newFile()
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
