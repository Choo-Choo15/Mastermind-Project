/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_board
{
public:
    QAction *actionNew_Game;
    QAction *actionExit;
    QAction *actionInstructions;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *clearButton;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *board)
    {
        if (board->objectName().isEmpty())
            board->setObjectName(QStringLiteral("board"));
        board->resize(431, 822);
        board->setStyleSheet(QLatin1String("selection-color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(0, 0, 0);"));
        actionNew_Game = new QAction(board);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionExit = new QAction(board);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionInstructions = new QAction(board);
        actionInstructions->setObjectName(QStringLiteral("actionInstructions"));
        actionAbout = new QAction(board);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(board);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(board);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 702, 391, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(20, 0, 20, 0);
        submitButton = new QPushButton(horizontalLayoutWidget);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(submitButton->sizePolicy().hasHeightForWidth());
        submitButton->setSizePolicy(sizePolicy);
        submitButton->setStyleSheet(QStringLiteral("background-color: rgb(230, 230, 230);"));

        horizontalLayout->addWidget(submitButton);

        clearButton = new QPushButton(horizontalLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setStyleSheet(QStringLiteral("background-color: rgb(230, 230, 230);"));

        horizontalLayout->addWidget(clearButton);

        board->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(board);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 431, 21));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        board->setMenuBar(menuBar);
        mainToolBar = new QToolBar(board);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        board->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(board);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        board->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionNew_Game);
        menuGame->addSeparator();
        menuGame->addAction(actionExit);
        menuHelp->addAction(actionInstructions);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(board);

        QMetaObject::connectSlotsByName(board);
    } // setupUi

    void retranslateUi(QMainWindow *board)
    {
        board->setWindowTitle(QApplication::translate("board", "MASTERMIND", Q_NULLPTR));
        actionNew_Game->setText(QApplication::translate("board", "New Game", Q_NULLPTR));
        actionExit->setText(QApplication::translate("board", "Exit", Q_NULLPTR));
        actionInstructions->setText(QApplication::translate("board", "Instructions", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("board", "About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("board", "About Qt", Q_NULLPTR));
        submitButton->setText(QApplication::translate("board", "SUBMIT", Q_NULLPTR));
        clearButton->setText(QApplication::translate("board", "UNDO/CLEAR", Q_NULLPTR));
        menuGame->setTitle(QApplication::translate("board", "Game", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("board", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class board: public Ui_board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
