#ifndef BACKROUND_H
#define BACKROUND_H

#include <QWidget>

namespace Ui {
class Backround;
}

class Backround : public QWidget
{
    Q_OBJECT

public:
    explicit Backround(QWidget *parent = nullptr);
    ~Backround();

private:
    Ui::Backround *ui;

    virtual void paintEvent(QPaintEvent *event);
};

#endif // BACKROUND_H
