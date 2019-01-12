#include <QPalette>

#include "mybutton.h"
#include "color_constants.h"

MyButton::MyButton(QWidget *parent) : QPushButton (parent)
{
    this->setMouseTracking(true);
    this->setAutoFillBackground(true);
    this->setFlat(true);
    pal = std::make_shared<QPalette>();
    connect(this, &MyButton::toggled, this, &MyButton::on_toggled);
}

void MyButton::on_toggled(bool checked)
{
    if (checked)
    {
        auto palette = pal;
        pal->setColor(QPalette::Button, MainColors::BUTTON_PR_BACLGROUND);
        pal->setColor(QPalette::ButtonText, MainColors::TEXT_BUTTON_PR);
        this->setPalette(*pal);
    }
    if (!checked)
    {
        auto palette = pal;
        pal->setColor(QPalette::Button, MainColors::BUTTON_NF_BACKGROUND);
        pal->setColor(QPalette::ButtonText, MainColors::TEXT_MAIN);
        this->setPalette(*pal);
    }
}
void MyButton::enterEvent(QEvent *)
{
    pal->setColor(QPalette::Button, MainColors::BUTTON_MF_BACKGROUND);
    pal->setColor(QPalette::ButtonText, MainColors::TEXT_BUTTON_MF);
    this->setPalette(*pal);
}

void MyButton::leaveEvent(QEvent *)
{
    if (!this->isChecked())
    {
        auto palette = pal;
        pal->setColor(QPalette::Button, MainColors::BUTTON_NF_BACKGROUND);
        pal->setColor(QPalette::ButtonText, MainColors::TEXT_MAIN);
        this->setPalette(*pal);
    }
}




