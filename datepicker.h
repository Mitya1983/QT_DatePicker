#ifndef DATEPICKER_H
#define DATEPICKER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDate>

#include "listpicker.h"
#include "hoverbutton.h"

class DatePicker : public QWidget
{
    Q_OBJECT

public:
    DatePicker(QWidget *parent = nullptr);
    QString dateToString();
    QDate date();
private:
    /*Storing date*/
    QDate *_date;
    int day, month, year;
    /*Placing widgets*/
    QHBoxLayout *listsLayout;
    QVBoxLayout *_layout;

public: /*Destructor*/
    ~DatePicker() = default;
};

#endif // DATEPICKER_H
