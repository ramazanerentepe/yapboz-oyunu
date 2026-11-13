#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "parca.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void hamleGuncelle();

private:
    Ui::MainWindow *ui;
    QGridLayout *grid;
    QList<Parca*> parcalar;
    QLabel *hamleSayac;
    const int N = 5;

};
#endif // MAINWINDOW_H
