#include "mainwindow.h"
#include "login/LoginWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget login;
    MainWindow w;

    QObject::connect(&login, &LoginWidget::emitLoginSuccesful, &w, [&](){
        login.hide();
        w.show();
    });

    login.show();
    return a.exec();
}
