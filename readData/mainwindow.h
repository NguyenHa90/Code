#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTimer>
#include <unistd.h>
#include <QMutex>
#include <QDebug>
#include "autoio.h"
#include <QSettings>
#include <qsettings.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    //Khai bao bien kieu so nguyen
    int                     n_X1L;
    int                     n_X1R;
    int                     n_X2L;
    int                     n_X2R;
    int                     n_X3L;
    int                     n_X3R;
    int                     n_Y1;
    int                     n_Y2;
    int                     n_Y3;
    //Khai bao bien kieu string
    QString                 pathSafety_Offset;
    //Khai bao bien timer
    QTimer*                 m_Function;
    //Khai bao con tro
    AutoIO                  *p_ThreadIO;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InnitData();
    int readini(QString strPath_ini, QString strKey, QString strKeyValue);
    int writeini(QString strPath_ini, QString strKey, QString strKeyValue, int nValue);

private:
    Ui::MainWindow *ui;

private slots:
    void Function();
    void on_btn_OffsetSafety_clicked();
};

#endif // MAINWINDOW_H
