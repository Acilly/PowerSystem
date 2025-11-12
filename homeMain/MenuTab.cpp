#include "MenuTab.h"
#include "ui_MenuTab.h"
#include "StartBar.h"
#include <QVBoxLayout>

MenuTab::MenuTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuTab)
{
    ui->setupUi(this);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MenuTab::pageChanged);

    // 将 StartBar 放到第一个标签页“开始”中
    auto startBar = new StartBar(this);
    auto layout = new QVBoxLayout(ui->tab_Start);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(startBar);

}

MenuTab::~MenuTab()
{
    delete ui;
}
