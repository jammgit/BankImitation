#ifndef CQUEUEIMITATION_H
#define CQUEUEIMITATION_H

#include <QMainWindow>
#include "qtheader.h"

class CQueueImitation : public QMainWindow
{
    Q_OBJECT
public:
    CQueueImitation(QWidget *parent = NULL);
    ~CQueueImitation();

    void initWidget();
private:
    QGraphicsScene *m_pBankScene;
    QGraphicsView *m_pBankView;

    QLabel *m_pBankMoney;

private:
    QWidget *m_pParent;
};

#endif // QUEUEIMITATION_H
