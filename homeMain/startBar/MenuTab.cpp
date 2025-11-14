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

    connect(startBar, &StartBar::openRequested, this, &MenuTab::openRequested);
    connect(startBar, &StartBar::saveRequested, this, &MenuTab::saveRequested);
    connect(startBar, &StartBar::newRequested, this, &MenuTab::newRequested);
    connect(startBar, &StartBar::closeRequested, this, &MenuTab::closeRequested);
    connect(startBar, &StartBar::refreshRequested, this, &MenuTab::refreshRequested);
    connect(startBar, &StartBar::renameRequested, this, &MenuTab::renameRequested);
    connect(startBar, &StartBar::exportRequested, this, &MenuTab::exportRequested);
    connect(startBar, &StartBar::importRequested, this, &MenuTab::importRequested);
    connect(startBar, &StartBar::findRequested, this, &MenuTab::findRequested);
    connect(startBar, &StartBar::projectManageRequested, this, &MenuTab::projectManageRequested);
    connect(startBar, &StartBar::engineManageRequested, this, &MenuTab::engineManageRequested);
    connect(startBar, &StartBar::deleteRequested, this, &MenuTab::deleteRequested);
    connect(startBar, &StartBar::redoRequested, this, &MenuTab::redoRequested);
    connect(startBar, &StartBar::compileRequested, this, &MenuTab::compileRequested);
    connect(startBar, &StartBar::publishRequested, this, &MenuTab::publishRequested);
    connect(startBar, &StartBar::dataImportRequested, this, &MenuTab::dataImportRequested);
    connect(startBar, &StartBar::flowPublishRequested, this, &MenuTab::flowPublishRequested);
    connect(startBar, &StartBar::operationLogRequested, this, &MenuTab::operationLogRequested);
    connect(startBar, &StartBar::dataExportRequested, this, &MenuTab::dataExportRequested);
    connect(startBar, &StartBar::optionsRequested, this, &MenuTab::optionsRequested);

}

MenuTab::~MenuTab()
{
    delete ui;
}
