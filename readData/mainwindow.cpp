#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
//Ham khoi tao
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //link offset file safety
    pathSafety_Offset = "/home/pi/Practice/readData/dataFile/Safety_Offset.ini";
    //chay ham khoi tao
    InnitData();
    //khoi tao timer chay
    m_Function = new QTimer(this);
    connect(m_Function, SIGNAL(timeout()), this, SLOT(Function()), Qt::AutoConnection);
    m_Function->start(50);
}
//Ham huy
MainWindow::~MainWindow()
{
    delete ui;
    delete p_ThreadIO;
}
//Ham khoi tao bien
void MainWindow::InnitData()
{
    p_ThreadIO = new AutoIO();
    p_ThreadIO->_startThread();
    //Read data from INI file
    n_X1L = readini(pathSafety_Offset,"Offset","X1L");
    n_X1R = readini(pathSafety_Offset,"Offset","X1R");
    n_X2L = readini(pathSafety_Offset,"Offset","X2L");
    n_X2R = readini(pathSafety_Offset,"Offset","X2R");
    n_X3L = readini(pathSafety_Offset,"Offset","X3L");
    n_X3R = readini(pathSafety_Offset,"Offset","X3R");
    n_Y1 = readini(pathSafety_Offset,"Offset","Y1");
    n_Y2 = readini(pathSafety_Offset,"Offset","Y2");
    n_Y3 = readini(pathSafety_Offset,"Offset","Y3");

    //Update to UI from INI file
    ui->le_x1l_2->setText(QString::number(n_X1L));
    ui->le_x1r_2->setText(QString::number(n_X1R));
    ui->le_x2l_2->setText(QString::number(n_X2L));
    ui->le_x2r_2->setText(QString::number(n_X2R));
    ui->le_x3l_2->setText(QString::number(n_X3L));
    ui->le_x3r_2->setText(QString::number(n_X3R));
    ui->le_y1_2->setText(QString::number(n_Y1));
    ui->le_y2_2->setText(QString::number(n_Y2));
    ui->le_y3_2->setText(QString::number(n_Y3));
}
//Loop process
void MainWindow::Function()
{
    usleep(1000);
}
//write to ini file
int MainWindow::writeini(QString strPath_ini, QString strKey, QString strKeyValue, int nValue)
{
    QSettings *configIniWrite = new QSettings(strPath_ini, QSettings::IniFormat);
    configIniWrite->beginGroup(strKey);
    configIniWrite->setValue(strKeyValue,nValue);
    configIniWrite->endGroup();
    delete configIniWrite;
    return 0;
}
//Read from ini file
int MainWindow::readini(QString strPath_ini, QString strKey, QString strKeyValue)
{
    int data;
    QSettings *configIniRead = new QSettings(strPath_ini, QSettings::IniFormat);
    configIniRead->beginGroup(strKey);
    data = configIniRead->value(strKeyValue).toInt();
    configIniRead->endGroup();
    delete configIniRead;
    return data;
}
//Click btn setting
void MainWindow::on_btn_OffsetSafety_clicked()
{
    //Get data from UI
    n_X1L = ui->le_x1l->text().toInt();
    n_X1R = ui->le_x1r->text().toInt();
    n_X2L = ui->le_x2l->text().toInt();
    n_X2R = ui->le_x2r->text().toInt();
    n_X3L = ui->le_x3l->text().toInt();
    n_X3R = ui->le_x3r->text().toInt();
    n_Y1 = ui->le_y1->text().toInt();
    n_Y2 = ui->le_y2->text().toInt();
    n_Y3 = ui->le_y3->text().toInt();
    // Write data to file INI after click button
    writeini(pathSafety_Offset,"Offset","X1L", n_X1L);
    writeini(pathSafety_Offset,"Offset","X1R", n_X1R);
    writeini(pathSafety_Offset,"Offset","X2L", n_X2L);
    writeini(pathSafety_Offset,"Offset","X2R", n_X2R);
    writeini(pathSafety_Offset,"Offset","X3L", n_X3L);
    writeini(pathSafety_Offset,"Offset","X3R", n_X3R);
    writeini(pathSafety_Offset,"Offset","Y1", n_Y1);
    writeini(pathSafety_Offset,"Offset","Y2", n_Y2);
    writeini(pathSafety_Offset,"Offset","Y3", n_Y3);
    // Update data from UI after click button
    ui->le_x1l_2->setText(QString::number(n_X1L));
    ui->le_x1r_2->setText(QString::number(n_X1R));
    ui->le_x2l_2->setText(QString::number(n_X2L));
    ui->le_x2r_2->setText(QString::number(n_X2R));
    ui->le_x3l_2->setText(QString::number(n_X3L));
    ui->le_x3r_2->setText(QString::number(n_X3R));
    ui->le_y1_2->setText(QString::number(n_Y1));
    ui->le_y2_2->setText(QString::number(n_Y2));
    ui->le_y3_2->setText(QString::number(n_Y3));
}
