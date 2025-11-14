#ifndef MENUTAB_H
#define MENUTAB_H

#include <QWidget>

namespace Ui
{
    class MenuTab;
}

class MenuTab : public QWidget
{
    Q_OBJECT

public:
    explicit MenuTab(QWidget *parent = nullptr);
    ~MenuTab();

signals:
    void pageChanged(int index);
    void openRequested();
    void saveRequested();
    void newRequested();
    void closeRequested();
    void refreshRequested();
    void deleteRequested();
    void redoRequested();
    void renameRequested();
    void exportRequested();
    void importRequested();
    void findRequested();
    void projectManageRequested();
    void engineManageRequested();
    void compileRequested();
    void publishRequested();
    void dataImportRequested();
    void flowPublishRequested();
    void operationLogRequested();
    void dataExportRequested();
    void optionsRequested();

private:
    Ui::MenuTab *ui;
};

#endif // MENUTAB_H
