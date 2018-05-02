#include "durandal.h"
#include "ui_durandal.h"

#include <QtWidgets>

Durandal::Durandal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Durandal)
{
    ui->setupUi(this);
}

Durandal::~Durandal()
{
    delete ui;
}

void Durandal::on_actionNew_triggered()
{
    if (maybeSave()) {
        currentFilename.clear();
        ui->plainTextEdit->setPlainText(QString());
    }
}

void Durandal::on_actionOpen_triggered()
{
    if (maybeSave()) {
        QString filename = QFileDialog::getOpenFileName(this, tr("Open File"));
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Warning"), tr("Cannot open file: ") + file.errorString());
            return;
        }
        currentFilename = filename;
        setWindowTitle(filename);
        // TODO: Read file in real-time
        QTextStream in(&file);
        QString text = in.readAll();
        ui->plainTextEdit->setPlainText(text);
        file.close();
    }
}

bool Durandal::on_actionSave_triggered()
{
    if (currentFilename.isEmpty()) {
        return on_actionSaveAs_triggered();
    }
    return saveFile(currentFilename);
}

bool Durandal::on_actionSaveAs_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"));
    currentFilename = filename;
    return saveFile(filename);
}

void Durandal::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

void Durandal::on_actionQuit_triggered()
{
    QWidget::close();
}

bool Durandal::saveFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Warning"), tr("Cannot save file: ") + file.errorString());
        return false;
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.close();
    return true;
}

bool Durandal::maybeSave() {
    if (!ui->plainTextEdit->document()->isModified()) {
        return true;
    }
    const QMessageBox::StandardButton ret =
            QMessageBox::warning(this, tr("Warning"),
                                 tr("This document has been modified\n"
                                    "Do you want to save your changes?"),
                                 QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return on_actionSave_triggered();
    case QMessageBox::Discard:
        return true;
    default:
        break;
    }
    return false;
}
