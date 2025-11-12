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

private:
    Ui::StartBar *ui;
};

#endif // STARTBAR_H
