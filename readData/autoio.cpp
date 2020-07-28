#include "autoio.h"

AutoIO::AutoIO(QObject *parent) : QObject(parent)
{
    bRunThread = false;
    setupIO();
}
AutoIO::~AutoIO()
{
    _stopThread();
}

bool AutoIO::readIO(int name)
{
    return digitalRead(100 + name);
}
void AutoIO::setupIO()
{
    wiringPiSetup();
    mcp23017Setup(100,0x20);
    mcp23017Setup(116,0x21);
    mcp23017Setup(132,0x22);
    mcp23017Setup(148,0x23);
    for(int i=0; i<=64;i++)
    {
        pinMode(100+i,INPUT);
        pullUpDnControl(100+i,PUD_UP);
    }
}
void AutoIO::_startThread()
{
    bRunThread = true;
    qDebug()<< "_startThread";
}
void AutoIO::_stopThread()
{
    bRunThread = false;
    qDebug()<< "_stopThread";
}
