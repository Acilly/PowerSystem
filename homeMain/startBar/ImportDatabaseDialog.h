#ifndef IMPORTDATABASEDIALOG_H
#define IMPORTDATABASEDIALOG_H

#include "BaseDialog.h"

namespace Ui
{
    class ImportDatabaseDialog;
}

class ImportDatabaseDialog : public BaseDialog
{
    Q_OBJECT
public:
    explicit ImportDatabaseDialog(QWidget *parent = nullptr);
    ~ImportDatabaseDialog();

protected:
    bool onAccept() override;

private:
    Ui::ImportDatabaseDialog *ui;
};

#endif // IMPORTDATABASEDIALOG_H
