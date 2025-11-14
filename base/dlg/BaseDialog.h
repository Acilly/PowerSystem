#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>

namespace Ui { class BaseDialog; }

class BaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BaseDialog(QWidget *parent = nullptr);
    ~BaseDialog();

    void setTitle(const QString &title);
    void setOkText(const QString &text);
    void setCancelText(const QString &text);
    QWidget *contentHost() const;
    void setHelpVisible(bool visible);

signals:
    void helpRequested();

protected:
    virtual bool onAccept();
    virtual void onHelp();

private:
    Ui::BaseDialog *ui;
    void handleAccept();
};

#endif // BASEDIALOG_H