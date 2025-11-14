#include "StartBar.h"
#include "ui_StartBar.h"
#include <QFileDialog>
#include <QAbstractButton>
#include <QStyle>
#include <QIcon>

StartBar::StartBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartBar)
{
    ui->setupUi(this);

    ui->btnOpen->setIcon(QIcon(":/icons/open.svg"));
    ui->btnSave->setIcon(QIcon(":/icons/save.svg"));

    ui->btnNew->setIcon(QIcon(":/icons/new.svg"));
    ui->btnClose->setIcon(QIcon(":/icons/close.svg"));
    ui->btnDelete->setIcon(QIcon(":/icons/delete.svg"));
    ui->btnRename->setIcon(QIcon(":/icons/rename.svg"));
    ui->btnExport->setIcon(QIcon(":/icons/export.svg"));
    ui->btnImport->setIcon(QIcon(":/icons/import.svg"));
    ui->btnFind->setIcon(QIcon(":/icons/find.svg"));
    ui->btnProjectManage->setIcon(QIcon(":/icons/project.svg"));

    ui->btnEngineManage->setIcon(QIcon(":/icons/engine.svg"));

    ui->btnRedo->setIcon(QIcon(":/icons/redo.svg"));

    ui->btnCompile->setIcon(QIcon(":/icons/compile.svg"));
    ui->btnPrjPublish->setIcon(QIcon(":/icons/publish.svg"));
    ui->btnDataImport->setIcon(QIcon(":/icons/data_import.svg"));
    ui->btnFlowPublish->setIcon(QIcon(":/icons/flow_publish.svg"));
    ui->btnOperationLog->setIcon(QIcon(":/icons/operation_log.svg"));
    if (ui->btnDataExport)
    {
        ui->btnDataExport->setIcon(QIcon(":/icons/db_export.svg"));
    }
    if (ui->btnOpt)
    {
        ui->btnOpt->setIcon(QIcon(":/icons/options.svg"));
    }

    connect(ui->btnOpen, &QAbstractButton::clicked, this, [this]()
    {
        emit openRequested();
    });
    connect(ui->btnSave, &QAbstractButton::clicked, this, [this]()
    {
        emit saveRequested();
    });
    connect(ui->btnNew, &QAbstractButton::clicked, this, [this]()
    {
        emit newRequested();
    });
    connect(ui->btnClose, &QAbstractButton::clicked, this, [this]()
    {
        emit closeRequested();
    });
    connect(ui->btnDelete, &QAbstractButton::clicked, this, [this]()
    {
        emit deleteRequested();
    });
    connect(ui->btnRename, &QAbstractButton::clicked, this, [this]()
    {
        emit renameRequested();
    });
    connect(ui->btnExport, &QAbstractButton::clicked, this, [this]()
    {
        emit exportRequested();
    });
    connect(ui->btnImport, &QAbstractButton::clicked, this, [this]()
    {
        emit importRequested();
    });
    connect(ui->btnFind, &QAbstractButton::clicked, this, [this]()
    {
        emit findRequested();
    });
    connect(ui->btnProjectManage, &QAbstractButton::clicked, this, [this]()
    {
        emit projectManageRequested();
    });
    connect(ui->btnEngineManage, &QAbstractButton::clicked, this, [this]()
    {
        emit engineManageRequested();
    });
    connect(ui->btnRedo, &QAbstractButton::clicked, this, [this]()
    {
        emit redoRequested();
    });
    connect(ui->btnCompile, &QAbstractButton::clicked, this, [this]()
    {
        emit compileRequested();
    });
    connect(ui->btnPrjPublish, &QAbstractButton::clicked, this, [this]()
    {
        emit publishRequested();
    });
    connect(ui->btnDataImport, &QAbstractButton::clicked, this, [this]()
    {
        emit dataImportRequested();
    });
    connect(ui->btnFlowPublish, &QAbstractButton::clicked, this, [this]()
    {
        emit flowPublishRequested();
    });
    connect(ui->btnOperationLog, &QAbstractButton::clicked, this, [this]()
    {
        emit operationLogRequested();
    });
    connect(ui->btnDataExport, &QAbstractButton::clicked, this, [this]()
    {
        emit dataExportRequested();
    });
    connect(ui->btnOpt, &QAbstractButton::clicked, this, [this]()
    {
        emit optionsRequested();
    });
}

StartBar::~StartBar()
{
    delete ui;
}
