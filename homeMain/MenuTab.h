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
//    void fileOpened(const QString &path);

private:
    Ui::MenuTab *ui;
};

#endif // MENUTAB_H
