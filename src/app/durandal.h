#ifndef DURANDAL_H
#define DURANDAL_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class Durandal;
}

class Durandal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Durandal(QWidget *parent = 0);
    ~Durandal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    bool on_actionSave_triggered();

    bool on_actionSaveAs_triggered();

    void on_actionQuit_triggered();

private:
    Ui::Durandal *ui;
    QString currentFilename;

    bool saveFile(const QString &filename);
    bool maybeSave();
};

#endif // DURANDAL_H
