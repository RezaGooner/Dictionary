/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *delButton;
    QPushButton *addButton;
    QTextBrowser *meaningBox;
    QPushButton *findButton;
    QLabel *guideLabel;
    QTextEdit *textEdit;
    QLabel *loadLabel;
    QListWidget *suggestBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(904, 302);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        delButton = new QPushButton(centralwidget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setGeometry(QRect(550, 180, 91, 29));
        QFont font;
        font.setFamily(QString::fromUtf8("B Titr"));
        font.setBold(true);
        delButton->setFont(font);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(650, 180, 101, 29));
        addButton->setFont(font);
        meaningBox = new QTextBrowser(centralwidget);
        meaningBox->setObjectName(QString::fromUtf8("meaningBox"));
        meaningBox->setGeometry(QRect(550, 70, 301, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Book Antiqua"));
        font1.setPointSize(10);
        meaningBox->setFont(font1);
        findButton = new QPushButton(centralwidget);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(760, 180, 91, 29));
        findButton->setFont(font);
        guideLabel = new QLabel(centralwidget);
        guideLabel->setObjectName(QString::fromUtf8("guideLabel"));
        guideLabel->setGeometry(QRect(60, 50, 481, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("B Kamran"));
        font2.setPointSize(12);
        font2.setBold(true);
        guideLabel->setFont(font2);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(60, 70, 481, 31));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setAutoFillBackground(true);
        loadLabel = new QLabel(centralwidget);
        loadLabel->setObjectName(QString::fromUtf8("loadLabel"));
        loadLabel->setGeometry(QRect(670, 220, 63, 51));
        suggestBox = new QListWidget(centralwidget);
        suggestBox->setObjectName(QString::fromUtf8("suggestBox"));
        suggestBox->setGeometry(QRect(60, 110, 481, 131));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 904, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        delButton->setText(QCoreApplication::translate("MainWindow", "\330\255\330\260\331\201", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\330\247\330\266\330\247\331\201\331\207", nullptr));
        meaningBox->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Book Antiqua'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        meaningBox->setPlaceholderText(QString());
        findButton->setText(QCoreApplication::translate("MainWindow", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        guideLabel->setText(QString());
#if QT_CONFIG(whatsthis)
        textEdit->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\332\251\331\204\331\205\331\207 \330\247\333\214 \330\261\330\247 \331\210\330\247\330\261\330\257 \331\206\331\205\330\247\333\214\333\214\330\257...", nullptr));
        loadLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
