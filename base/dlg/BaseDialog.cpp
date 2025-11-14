#include "BaseDialog.h"
#include "ui_BaseDialog.h"
#include <QDialogButtonBox>
#include <QPushButton>

BaseDialog::BaseDialog(QWidget *parent) : QDialog(parent), ui(new Ui::BaseDialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowContextHelpButtonHint);
    resize(520, 360);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &BaseDialog::handleAccept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &BaseDialog::reject);
}

BaseDialog::~BaseDialog()
{
    delete ui;
}

void BaseDialog::setTitle(const QString &title)
{
    setWindowTitle(title);
}

void BaseDialog::setOkText(const QString &text)
{
    auto ok = ui->buttonBox->button(QDialogButtonBox::Ok);
    if (ok) ok->setText(text);
}

void BaseDialog::setCancelText(const QString &text)
{
    auto cancel = ui->buttonBox->button(QDialogButtonBox::Cancel);
    if (cancel) cancel->setText(text);
}

QWidget *BaseDialog::contentHost() const
{
    return ui->contentHost;
}

void BaseDialog::setHelpVisible(bool visible)
{
    Q_UNUSED(visible);
}

bool BaseDialog::onAccept()
{
    return true;
}

void BaseDialog::onHelp() {}

void BaseDialog::handleAccept()
{
    if (onAccept()) accept();
}