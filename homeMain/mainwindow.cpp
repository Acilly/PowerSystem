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

    // 连接 MenuTab 转发的 fileOpened 信号，仅用于状态栏反馈
//    connect(menuTab, &MenuTab::fileOpened, this, [this](const QString &path){
//        statusBar()->showMessage(tr("打开: %1").arg(path), 3000);
//    });



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

