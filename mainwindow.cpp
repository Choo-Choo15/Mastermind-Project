#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Mastermind"));
    setMinimumSize(160, 160);
    resize(520, 820);
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::newGame()
{
    infoLabel->setText(tr("Invoked <b>Game|New</b>"));
}

void MainWindow::instructions()
{
    infoLabel->setText(tr("Invoked <b>Help|Instructions</b>"));
    QMessageBox::about(this, tr("Instructions Menu"),
            tr("Instructions......."));
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
            tr("Mastermind Game"));
}

void MainWindow::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}

void MainWindow::createActions()
{
    newGameAct = new QAction(tr("&New"), this);
    newGameAct->setShortcuts(QKeySequence::New);
    newGameAct->setStatusTip(tr("Start new game"));
    connect(newGameAct, &QAction::triggered, this, &MainWindow::newGame);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    instructionsAct = new QAction(tr("&Instructions"), this);
    instructionsAct->setStatusTip(tr("Show the application's instructions box"));
    connect(instructionsAct, &QAction::triggered, this, &MainWindow::instructions);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Game"));
    fileMenu->addAction(newGameAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(instructionsAct);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

}
