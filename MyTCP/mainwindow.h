#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //连接开关的范围
    QRect frame_switch;
    //主副机切换的范围
    QRect frame_Mode;
    //发送按键的范围
    QRect frame_Send;
    //清空接收区的范围
    QRect frame_Receive;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    QMessageBox *msgBox;

public slots:
    void Connected_Slot();
    void NewConnection_Slot();
    void ReadyReadConnection_Slot();
    void Disconnect_Slot();
    void SwitchOn_Slot();
    void SendBit_Slot();

private:
    Ui::MainWindow *ui;

    void mousePressEvent(QMouseEvent *event);

    void Tcp_Init();
    void Change_Mode();
    void Reaceive_Clean();
};
#endif // MAINWINDOW_H
