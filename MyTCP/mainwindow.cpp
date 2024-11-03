#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MS = true;//t 主机
bool flag_Sw = false;//开关状态

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("监控");
    setWindowIcon(QIcon(":/new/prefix1/image/app.png"));

    Tcp_Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Tcp_Init()
{
    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    //Switch_But的按下范围
    frame_switch.adjust(150, 245, 290, 265);

    //Switch_But的按下范围
    frame_Mode.adjust(328, 200, 369, 241);

    //Send_but的按下范围
    frame_Send.adjust(360, 310, 386, 336);

    //Receive_Clean的按下范围
    frame_Receive.adjust(360, 275, 390, 305);

    //开启时按切换等出现的弹窗初始化
    msgBox = new QMessageBox(this);

    //默认为主机模式，创建后就等待新的连接
    connect(tcpServer, &QTcpServer::newConnection, this, &MainWindow::NewConnection_Slot);

    //默认设置的ip和端口号
    ui->IpLine->setText("192.168.1.181");
    ui->PortLine->setText("8080");
}


//作为主机时
void MainWindow::NewConnection_Slot()
{
    tcpSocket = tcpServer->nextPendingConnection();

    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::ReadyReadConnection_Slot);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::Disconnect_Slot);
    ui->StateRight_label->setPixmap(QPixmap(":/new/prefix1/image/connect.png"));
}

//断开联系
void MainWindow::Disconnect_Slot()
{
    tcpSocket->close();
    ui->StateRight_label->setPixmap(QPixmap(":/new/prefix1/image/discon.png"));
}

//客户端
void MainWindow::Connected_Slot()
{
    connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::ReadyReadConnection_Slot);
    ui->StateRight_label->setPixmap(QPixmap(":/new/prefix1/image/connect.png"));
    connect(tcpSocket, &QTcpSocket::disconnected, this, &MainWindow::Disconnect_Slot);
}


//接收数据
void MainWindow::ReadyReadConnection_Slot()
{
    QByteArray Receive_Data;
    QTextCodec *tc = QTextCodec::codecForName("GBK");  //编码转换,必须转换编码，否则乱码

    while(!tcpSocket->atEnd())
    {
        Receive_Data = tcpSocket->readAll();
    }

    if(!Receive_Data.isEmpty())
    {
        QString PlainData = tc->toUnicode(Receive_Data);
        ui->Receive_area->appendPlainText(PlainData);
    }
    Receive_Data.clear();
}


//发送数据
void MainWindow::SendBit_Slot()
{
    //封装编码
    QByteArray receiveDate;
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");  //编码转换,必须转换编码，否则乱码

    if(flag_Sw)
    {
        receiveDate = ui->Send_area->toPlainText().toLocal8Bit().data();
        QString strBuf = tc->toUnicode(receiveDate);


        QString str = "->";
        QString str2 = str.append(strBuf);

        //回显
        ui->Receive_area->appendPlainText(str2);

        tcpSocket->write(receiveDate);
    }

}


//改写的MousePressEvent
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(frame_switch.contains(event->pos()))
        {
            SwitchOn_Slot();
        }
        if(frame_Mode.contains(event->pos()))
        {
            Change_Mode();
        }
        if(frame_Send.contains(event->pos()))
        {
            SendBit_Slot();
        }
        if(frame_Receive.contains((event->pos())))
        {
            Reaceive_Clean();
        }
    }
}


//连接开始按键
void MainWindow::SwitchOn_Slot()
{
    flag_Sw = !flag_Sw;
    if(flag_Sw)
    {
        if(MS)
        {
            tcpServer->listen(QHostAddress::Any,ui->PortLine->text().toUInt());
        }
        else
        {
            tcpSocket->connectToHost(ui->IpLine->text(), ui->PortLine->text().toUInt());
            connect(tcpSocket, &QTcpSocket::connected, this, &MainWindow::Connected_Slot);
        }
        ui->Switch_but->setPixmap(QPixmap(":/new/prefix1/image/open.png"));
        ui->Wifi_label->setPixmap(QPixmap(":/new/prefix1/image/wifi_on.png"));
        ui->IpLine->setReadOnly(true);
        ui->PortLine->setReadOnly(true);
    }
    else
    {
        tcpServer->close();
        tcpSocket->close();
        ui->Switch_but->setPixmap(QPixmap(":/new/prefix1/image/close.png"));
        ui->Wifi_label->setPixmap(QPixmap(":/new/prefix1/image/wifi_off.png"));
        ui->IpLine->setReadOnly(false);
        ui->PortLine->setReadOnly(false);
    }

}

//主副机切换
void MainWindow::Change_Mode()
{
    if(!flag_Sw)
    {
        tcpServer->close();
        tcpSocket->close();
        if(MS)  //主机
        {
            MS = false;
            ui->State_label->setText("客户端模式");
            ui->label_5->setPixmap(QPixmap(":/new/prefix1/image/client.png"));
            ui->StateRight_label->setPixmap(QPixmap(":/new/prefix1/image/discon.png"));
        }
        else
        {
            MS = true;
            ui->State_label->setText("主机模式");
            ui->label_5->setPixmap(QPixmap(":/new/prefix1/image/server.png"));
            ui->StateRight_label->setPixmap(QPixmap(":/new/prefix1/image/discon.png"));
        }
    }
    else
    {
        msgBox->critical(this, "警告", "连接中请勿进行其他操作", QMessageBox::Ok, QMessageBox::Ok);
    }
}


//清空接收窗口
void MainWindow::Reaceive_Clean()
{
    ui->Receive_area->clear();
}



