#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class QAction;
class QToolBar;
class MenuTab;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MenuTab *menuTab;


private slots:
    void onOpenProject();
    void onSaveProject();
    void onImportData();
    void onPublishProject();
    void onRenameProject();
    void onDeleteProject();

private:

};
#endif // MAINWINDOW_H
