#ifndef DURANDAL_H
#define DURANDAL_H

#include <QMainWindow>

namespace Ui {
class Durandal;
}

class Durandal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Durandal(QWidget *parent = 0);
    ~Durandal();

private:
    Ui::Durandal *ui;
};

#endif // DURANDAL_H
