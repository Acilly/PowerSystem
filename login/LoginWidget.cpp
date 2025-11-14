#include "LoginWidget.h"
#include "ui_LoginWidget.h"
#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QPalette>
#include <QGraphicsOpacityEffect>
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QLineEdit>


LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    QFile file(":/qss/main.qss");

    file.open(QFile::ReadOnly);

    QTextStream filetext(&file);

    QString stylesheet = filetext.readAll();

    this->setStyleSheet(stylesheet);

    file.close();

    if(!initialization())
    {
        qDebug() << "初始化失败！";
    }

    initConnect();
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

bool LoginWidget::initialization()
{

    QGraphicsOpacityEffect *effce_Widget = new QGraphicsOpacityEffect(ui->widget);
    effce_Widget->setOpacity(1);
    ui->widget->setGraphicsEffect(effce_Widget);



    ui->icon2->resize(QPixmap(":/images/icon2.png").size());
    ui->icon2->setScaledContents(true);
    ui->icon2->setPixmap(QPixmap(":/images/icon2.png"));

    ui->title->resize(QPixmap(":/images/title.png").size());
    ui->title->setScaledContents(true);
    ui->title->setPixmap(QPixmap(":/images/title.png"));
    ui->title->setAlignment(Qt::AlignCenter);

    ui->ground1->resize(QPixmap(":/images/ground1.png").size());
    ui->ground1->setScaledContents(true);
    ui->ground1->setPixmap(QPixmap(":/images/ground1.png"));


    ui->ground2->resize(QPixmap(":/images/ground2.png").size());
    ui->ground2->setScaledContents(true);
    ui->ground2->setPixmap(QPixmap(":/images/ground2.png"));

    ui->imag->resize(QPixmap(":/images/imag.png").size());
    ui->imag->setScaledContents(true);
    ui->imag->setPixmap(QPixmap(":/images/imag.png"));

    ui->Password->setEchoMode(QLineEdit::Password);




    return true;
}

void LoginWidget::initConnect()
{

    connect(ui->LoginBtn, &QPushButton::clicked, this, [ = ]()
    {
        if(ui->Account->text().isEmpty())
        {
            return;
        }
        if(ui->Account->text().count() != 11)
        {
            return;
        }
        if(ui->Password->text().isEmpty())
        {
            return;
        }
        QString phoneNumber = ui->Account->text();
        QString pwd = ui->Password->text();
        QString token = "";

        emit emitLoginSuccesful();
    });
}



void LoginWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap background(":/images/Login_Back.png");
    painter.drawPixmap(0, 0, width(), height(), background);
    QWidget::paintEvent(event);

}

