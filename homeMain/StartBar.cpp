#include "StartBar.h"
#include "ui_StartBar.h"
#include <QFileDialog>
#include <QAbstractButton>

StartBar::StartBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartBar)
{
    ui->setupUi(this);

    // 打开按钮行为（逻辑在 StartBar 内部）
    connect(ui->btnOpen, &QAbstractButton::clicked, this, [this]()
    {
        const QString path = QFileDialog::getOpenFileName(
                                 this,
                                 tr("打开工程"),
                                 QString(),
                                 tr("工程文件 (*.json *.proj);;所有文件 (*.*)"));
        if (!path.isEmpty())
        {
//            emit fileOpened(path);
        }
    });
}

StartBar::~StartBar()
{
    delete ui;
}
