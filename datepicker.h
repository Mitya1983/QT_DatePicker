#ifndef DATEPICKER_H
#define DATEPICKER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

class DatePicker : public QWidget
{
    Q_OBJECT

public:
    DatePicker(QWidget *parent = nullptr);
private:

public: /*Destructor*/
    ~DatePicker() = default;
};

#endif // DATEPICKER_H
