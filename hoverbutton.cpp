#include <QPalette>
#include <QDebug>

#include "hoverbutton.h"

HoverButton::HoverButton(QWidget *parent):
    QPushButton (parent),
    baseColor (parent == nullptr ? QColor(255, 255, 255, 255) : parent->palette().button().color()),
    hoverColor (baseColor.darker(125)),
    pressedColor (baseColor.darker(300)),
    pressedTextColor (baseColor)

{
    mainSetup();
    setBaseColor();
    connect(this, &HoverButton::toggled, this, &HoverButton::on_toggled);
}

HoverButton::HoverButton(QColor _baseColor, QColor _hoverColor, QWidget *parent) :
    QPushButton (parent),
    baseColor(std::move(_baseColor)),
    hoverColor (std::move(_hoverColor)),
    pressedColor(baseColor.darker(300)),
    pressedTextColor(baseColor)

{
    mainSetup();
    setBaseColor();
    connect(this, &HoverButton::toggled, this, &HoverButton::on_toggled);
}

HoverButton::HoverButton(QColor _baseColor, QColor _hoverColor, QColor _pressedColor, QColor _pressedTextColor, QWidget *parent):
    QPushButton (parent),
    baseColor(std::move(_baseColor)),
    hoverColor(std::move(_hoverColor)),
    pressedColor(std::move(_pressedColor)),
    pressedTextColor(std::move(_pressedTextColor))
{
    mainSetup();
    setBaseColor();
    connect(this, &HoverButton::toggled, this, &HoverButton::on_toggled);
}

void HoverButton::mainSetup()
{
    setAutoFillBackground(true);
    setFlat(true);
    setMouseTracking(true);
    setTabletTracking(true);
}

void HoverButton::setBaseColor()
{
    QPalette pal = palette();
    pal.setColor(QPalette::Button, baseColor);
    if (initialTextColor != QColor("Invalid"))
        pal.setColor(QPalette::ButtonText, initialTextColor);
    setPalette(pal);
}

void HoverButton::setHoverColor()
{
    QPalette pal = palette();
    pal.setColor(QPalette::Button, hoverColor);
    setPalette(pal);
}

void HoverButton::setPressedColor()
{
    initialTextColor = palette().buttonText().color();
    QPalette pal = palette();
    pal.setColor(QPalette::Button, pressedColor);
    pal.setColor(QPalette::ButtonText, pressedTextColor);
    setPalette(pal);
}

void HoverButton::enterEvent(QEvent *event)
{
    if (!isChecked())
    {
        setHoverColor();
        event->accept();
    }
    else
        event->ignore();
}

void HoverButton::leaveEvent(QEvent *event)
{
    if(!isChecked())
    {
        setBaseColor();
        event->accept();
    }
    else
        event->ignore();
}

void HoverButton::on_toggled(bool checked)
{
    if (checked)
        setPressedColor();
    if (!checked)
        setBaseColor();
}
