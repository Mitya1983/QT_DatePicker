#ifndef DATEPICKER_H
#define DATEPICKER_H

#include <QWidget>

class DatePicker : public QWidget
{
    Q_OBJECT

public:
    DatePicker(QWidget *parent = 0);
    ~DatePicker();
};

#endif // DATEPICKER_H
