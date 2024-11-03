/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPlainTextEdit *Receive_area;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *IpLine;
    QFrame *line;
    QLineEdit *PortLine;
    QLabel *label;
    QLabel *label_2;
    QFrame *line_2;
    QLabel *Wifi_label;
    QFrame *line_3;
    QLabel *Switch_but;
    QLabel *label_5;
    QLabel *State_label;
    QLabel *StateRight_label;
    QPlainTextEdit *Send_area;
    QLabel *Clean_but;
    QLabel *Send_but;
    QMenuBar *menubar;
    QStatusBar *statebar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(440, 379);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 391, 180));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        groupBox->setFont(font);
        groupBox->setCursor(QCursor(Qt::ArrowCursor));
        groupBox->setMouseTracking(false);
        groupBox->setTabletTracking(false);
        groupBox->setFocusPolicy(Qt::NoFocus);
        groupBox->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox->setAcceptDrops(false);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        Receive_area = new QPlainTextEdit(groupBox);
        Receive_area->setObjectName(QString::fromUtf8("Receive_area"));
        Receive_area->setGeometry(QRect(8, 20, 374, 151));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 200, 151, 71));
        widget->setTabletTracking(false);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        IpLine = new QLineEdit(widget);
        IpLine->setObjectName(QString::fromUtf8("IpLine"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IpLine->sizePolicy().hasHeightForWidth());
        IpLine->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(IpLine);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        PortLine = new QLineEdit(widget);
        PortLine->setObjectName(QString::fromUtf8("PortLine"));

        verticalLayout->addWidget(PortLine);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 200, 30, 30));
        label->setTextFormat(Qt::PlainText);
        label->setPixmap(QPixmap(QString::fromUtf8("image/ip.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 240, 30, 30));
        label_2->setPixmap(QPixmap(QString::fromUtf8("image/duan.png")));
        label_2->setScaledContents(true);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(220, 200, 3, 70));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        Wifi_label = new QLabel(centralwidget);
        Wifi_label->setObjectName(QString::fromUtf8("Wifi_label"));
        Wifi_label->setGeometry(QRect(254, 205, 30, 30));
        Wifi_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/wifi_off.png")));
        Wifi_label->setScaledContents(true);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(238, 235, 68, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        Switch_but = new QLabel(centralwidget);
        Switch_but->setObjectName(QString::fromUtf8("Switch_but"));
        Switch_but->setGeometry(QRect(250, 245, 40, 20));
        Switch_but->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/close.png")));
        Switch_but->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(328, 200, 41, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/server.png")));
        label_5->setScaledContents(true);
        State_label = new QLabel(centralwidget);
        State_label->setObjectName(QString::fromUtf8("State_label"));
        State_label->setGeometry(QRect(325, 250, 53, 15));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        State_label->setFont(font1);
        StateRight_label = new QLabel(centralwidget);
        StateRight_label->setObjectName(QString::fromUtf8("StateRight_label"));
        StateRight_label->setGeometry(QRect(370, 220, 21, 16));
        StateRight_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/discon.png")));
        StateRight_label->setScaledContents(true);
        Send_area = new QPlainTextEdit(centralwidget);
        Send_area->setObjectName(QString::fromUtf8("Send_area"));
        Send_area->setGeometry(QRect(30, 280, 311, 51));
        Clean_but = new QLabel(centralwidget);
        Clean_but->setObjectName(QString::fromUtf8("Clean_but"));
        Clean_but->setGeometry(QRect(360, 275, 30, 30));
        Clean_but->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/clearS.png")));
        Clean_but->setScaledContents(true);
        Send_but = new QLabel(centralwidget);
        Send_but->setObjectName(QString::fromUtf8("Send_but"));
        Send_but->setGeometry(QRect(360, 310, 26, 26));
        Send_but->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/send.png")));
        Send_but->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 440, 21));
        MainWindow->setMenuBar(menubar);
        statebar = new QStatusBar(MainWindow);
        statebar->setObjectName(QString::fromUtf8("statebar"));
        MainWindow->setStatusBar(statebar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        Wifi_label->setText(QString());
        Switch_but->setText(QString());
        label_5->setText(QString());
        State_label->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272\346\250\241\345\274\217", nullptr));
        StateRight_label->setText(QString());
        Clean_but->setText(QString());
        Send_but->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
