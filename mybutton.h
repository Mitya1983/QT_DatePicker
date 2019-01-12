#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QPalette>
#include <memory>

class MyButton : public QPushButton
{
private:
    Q_OBJECT
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;
    std::shared_ptr<QPalette> pal;
public:
    explicit MyButton(QWidget *parent = nullptr);
    ~MyButton() override = default;
signals:
private slots:

    void on_toggled(bool checked);

};

#endif // MYBUTTON_H
