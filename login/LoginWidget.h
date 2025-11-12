#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QList>

#include "Backround.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class LoginWidget;
}
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;


private:

    bool initialization();
    void initConnect();

signals:
    void emitLoginSuccesful();

protected:

    virtual void paintEvent(QPaintEvent *event);


private slots:



};
#endif // LOGINWIDGET_H
