#ifndef ABC_H
#define ABC_H

#include <QObject>

class ABC : public QObject
{
    Q_OBJECT
public:
    explicit ABC(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ABC_H
