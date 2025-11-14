#ifndef STARTBAR_H
#define STARTBAR_H

#include <QWidget>

namespace Ui {
class StartBar;
}

class StartBar : public QWidget
{
    Q_OBJECT

public:
    explicit StartBar(QWidget *parent = nullptr);
    ~StartBar();

signals:
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
    Ui::StartBar *ui;
};

#endif // STARTBAR_H
