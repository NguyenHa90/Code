#ifndef AUTOIO_H
#define AUTOIO_H

#include <QObject>
#include <QDebug>
#include <mcp23017.h>
#include <wiringPi.h>

class AutoIO : public QObject
{
    Q_OBJECT
public:
    bool bRunThread;

public:
    explicit AutoIO(QObject *parent = nullptr);
    ~AutoIO();
    void setupIO();
    void _startThread();
    void _stopThread();
    bool readIO(int name);
signals:

public slots:
};

#endif // AUTOIO_H
