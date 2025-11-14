#include "ImportDatabaseDialog.h"
#include "ui_ImportDatabaseDialog.h"
#include <QFileDialog>
#include <QProgressBar>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QButtonGroup>

ImportDatabaseDialog::ImportDatabaseDialog(QWidget *parent) : BaseDialog(parent), ui(new Ui::ImportDatabaseDialog)
{
    setTitle(QStringLiteral("数据库导入"));
    setOkText(QStringLiteral("导入"));
    setCancelText(QStringLiteral("取消"));
    QWidget *page = new QWidget(contentHost());
    ui->setupUi(page);
    if (contentHost()->layout())
    {
        contentHost()->layout()->addWidget(page);
    }

    auto btn = contentHost()->findChild<QPushButton*>(QStringLiteral("btnSelectFile"));
    auto edit = contentHost()->findChild<QLineEdit*>(QStringLiteral("editTableFile"));
    auto progress = contentHost()->findChild<QProgressBar*>(QStringLiteral("progress"));
    auto rbClear = contentHost()->findChild<QRadioButton*>(QStringLiteral("rbClear"));
    auto rbIncrement = contentHost()->findChild<QRadioButton*>(QStringLiteral("rbIncrement"));
    auto rbSkip = contentHost()->findChild<QRadioButton*>(QStringLiteral("rbSkip"));
    auto rbOverwrite = contentHost()->findChild<QRadioButton*>(QStringLiteral("rbOverwrite"));
    if (progress)
    {
        progress->setValue(0);
    }
    if (btn && edit)
    {
        connect(btn, &QPushButton::clicked, this, [this, edit]()
        {
            QString path = QFileDialog::getOpenFileName(this, QStringLiteral("选择文件"), QString(), QStringLiteral("CSV (*.csv);;Excel (*.xlsx);;所有文件 (*.*)"));
            if (!path.isEmpty())
            {
                edit->setText(path);
            }
        });
    }

    if (rbClear && rbIncrement)
    {
        auto grpImport = new QButtonGroup(this);
        grpImport->addButton(rbClear);
        grpImport->addButton(rbIncrement);
        grpImport->setExclusive(true);
    }
    if (rbSkip && rbOverwrite)
    {
        auto grpDup = new QButtonGroup(this);
        grpDup->addButton(rbSkip);
        grpDup->addButton(rbOverwrite);
        grpDup->setExclusive(true);
    }
}

ImportDatabaseDialog::~ImportDatabaseDialog()
{
    delete ui;
}

bool ImportDatabaseDialog::onAccept()
{
    auto edit = contentHost()->findChild<QLineEdit*>(QStringLiteral("editTableFile"));
    if (!edit || edit->text().isEmpty())
    {
        return false;
    }
    return true;
}
