#ifndef EMAIL_H
#define EMAIL_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
namespace Ui {
class email;
}

class email : public QDialog
{
    Q_OBJECT

public:
    explicit email(QWidget *parent = nullptr);
    ~email();
    QLineEdit *fromLineEdit;
    QLineEdit *toLineEdit;
    QLineEdit *subjectLineEdit;
    QTextEdit *messageTextEdit;
private slots:
    void on_send_clicked();

    void on_cancel_clicked();

private:
    Ui::email *ui;
};

#endif // EMAIL_H
