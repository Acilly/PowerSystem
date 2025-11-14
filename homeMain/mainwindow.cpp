#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "MenuTab.h"
#include <QToolBar>
#include <QFileDialog>
#include <QStatusBar>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setVisible(false);
    ui->toolBar->setVisible(false);

    menuTab = new MenuTab(this);
    setMenuWidget(menuTab);

    ui->centralwidget->setStyleSheet("#w_Main{background-color:#9e9e9e;}");

    QList<QDockWidget *> docks{ ui->dockWidget, ui->dockWidget_2 };
    QList<int> sizes{ 280, 280 };
    resizeDocks(docks, sizes, Qt::Horizontal);

    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    setStyleSheet("QMainWindow::separator{width:1px;height:0px;background:transparent;margin:0;padding:0;} QDockWidget{border:1px;}");



    // 连接 MenuTab 转发的 fileOpened 信号，仅用于状态栏反馈
//    connect(menuTab, &MenuTab::fileOpened, this, [this](const QString &path){
//        statusBar()->showMessage(tr("打开: %1").arg(path), 3000);
//    });
    connect(menuTab, &MenuTab::openRequested, this, &MainWindow::onOpenProject);
    connect(menuTab, &MenuTab::saveRequested, this, &MainWindow::onSaveProject);
    connect(menuTab, &MenuTab::dataImportRequested, this, &MainWindow::onImportData);
    connect(menuTab, &MenuTab::publishRequested, this, &MainWindow::onPublishProject);
    connect(menuTab, &MenuTab::renameRequested, this, &MainWindow::onRenameProject);
    connect(menuTab, &MenuTab::closeRequested, this, &MainWindow::onDeleteProject);
    connect(menuTab, &MenuTab::deleteRequested, this, [this]()
    {
        statusBar()->showMessage("删除", 2000);
    });
    connect(menuTab, &MenuTab::redoRequested, this, [this]()
    {
        statusBar()->showMessage("恢复", 2000);
    });
    connect(menuTab, &MenuTab::newRequested, this, [this]()
    {
        statusBar()->showMessage("新建", 2000);
    });
    connect(menuTab, &MenuTab::refreshRequested, this, [this]()
    {
        statusBar()->showMessage("刷新", 2000);
    });
    connect(menuTab, &MenuTab::exportRequested, this, [this]()
    {
        statusBar()->showMessage("导出", 2000);
    });
    connect(menuTab, &MenuTab::importRequested, this, [this]()
    {
        statusBar()->showMessage("导入", 2000);
    });
    connect(menuTab, &MenuTab::findRequested, this, [this]()
    {
        statusBar()->showMessage("查找", 2000);
    });
    connect(menuTab, &MenuTab::projectManageRequested, this, [this]()
    {
        statusBar()->showMessage("项目管理", 2000);
    });
    connect(menuTab, &MenuTab::engineManageRequested, this, [this]()
    {
        statusBar()->showMessage("工程管理", 2000);
    });
    connect(menuTab, &MenuTab::compileRequested, this, [this]()
    {
        statusBar()->showMessage("编译", 2000);
    });
    connect(menuTab, &MenuTab::flowPublishRequested, this, [this]()
    {
        statusBar()->showMessage("流程图发布", 2000);
    });
    connect(menuTab, &MenuTab::operationLogRequested, this, [this]()
    {
        statusBar()->showMessage("操作日志", 2000);
    });
    connect(menuTab, &MenuTab::dataExportRequested, this, [this]()
    {
        statusBar()->showMessage("数据库导出", 2000);
    });
    connect(menuTab, &MenuTab::optionsRequested, this, [this]()
    {
        statusBar()->showMessage("选项", 2000);
    });
    statusBar()->showMessage("就绪");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::onOpenProject()
{
    auto path = QFileDialog::getOpenFileName(this, tr("打开工程"), QString(), tr("工程文件 (*.json *.proj);;所有文件 (*.*)"));
    if (!path.isEmpty())
    {
        statusBar()->showMessage(tr("打开: %1").arg(path), 3000);
    }
}

void MainWindow::onSaveProject()
{
    auto path = QFileDialog::getSaveFileName(this, tr("保存工程"), QString(), tr("工程文件 (*.json *.proj)"));
    if (!path.isEmpty())
    {
        statusBar()->showMessage(tr("保存: %1").arg(path), 3000);
    }
}

void MainWindow::onImportData()
{
    auto path = QFileDialog::getOpenFileName(this, tr("数据源导入"), QString(), tr("CSV (*.csv);;Excel (*.xlsx);;所有文件 (*.*)"));
    if (!path.isEmpty())
    {
        statusBar()->showMessage(tr("导入: %1").arg(path), 3000);
    }
}

void MainWindow::onPublishProject()
{
    statusBar()->showMessage(tr("工程发布..."), 3000);
}

void MainWindow::onRenameProject()
{
    statusBar()->showMessage(tr("重命名工程"), 2000);
}

void MainWindow::onDeleteProject()
{
    statusBar()->showMessage(tr("删除工程"), 2000);
}

