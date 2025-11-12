#include "Backround.h"
#include "ui_Backround.h"

#include <QPainter>
#include <QGraphicsOpacityEffect>
Backround::Backround(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Backround)
{
    ui->setupUi(this);
    QGraphicsOpacityEffect *effce_Widget = new QGraphicsOpacityEffect(this);
    effce_Widget->setOpacity(1);
    this->setGraphicsEffect(effce_Widget);
}

Backround::~Backround()
{
    delete ui;
}

void Backround::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap background(":/images/backround.png");
    painter.drawPixmap(0,0,width(),height(),background);
    QWidget::paintEvent(event);
}
