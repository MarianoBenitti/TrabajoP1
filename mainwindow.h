#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void OnQTimer1();

private slots:
    void on_startstop_clicked();

    void on_reset_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_SetTemp_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *QTimer1;

    int cont;
};
#endif // MAINWINDOW_H
