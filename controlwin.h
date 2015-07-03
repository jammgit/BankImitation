#ifndef CONTROLWIN_H
#define CONTROLWIN_H

#include "qtheader.h"
#include <QMainWindow>
// ****** data class ******
#include "myqueue.h"
#include "customertype.h"
#include "servertype.h"
#include <cstdlib>



class CControlWin : public QMainWindow
{
    Q_OBJECT
public:
    CControlWin(QWidget *parent = NULL);
    ~CControlWin();

    bool inputInfoCorrect();
    void renewCurCusLabelInfo();
    void renewQueueInfo();
    void setCusTipWait();
    void renewServerCus();

    void outputAverageTime();
    void reInitInfo();

    time_t randomProcessTime();
    money_t randomCusMoney();
    int randomNextCustomer();
    Business randomBusi();

public slots:
    void renewInfo();
    void myStart();
    void myStop();

private:
    void initWidget();
    void initConnect();
private:
    QWidget *m_pCenWidget;
    QGridLayout *m_pWidgetLayout;

private:
    QTimer *m_pTimer;
    // ****** 初始化数据提示变量 ******
    QLineEdit *m_pMoneyLine;
    QLabel *m_pMoneyLabel;
    QLineEdit *m_pFreLineLess;
    QLineEdit *m_pFreLineMore;
    QLabel *m_pFreLabel;
    QLineEdit *m_pProTimeLineLess;
    QLineEdit *m_pProTimeLineMore;
    QLabel *m_pProTimeLabel;
    QLineEdit *m_pWorkTimeLine;
    QLabel *m_pWorkTimeLabel;
    QLabel *m_pCusMoneyLabel;
    QLineEdit *m_pCusMoneyLineLess;
    QLineEdit *m_pCusMoneyLineMore;

    QLabel *tmp;
    QPushButton *m_pStartBtn;
    QPushButton *m_pStopBtn;
    // ****** 当前客户信息提示变量 ******
    QLabel *m_pNumConst;
    QLabel *m_pNumVar;
    QLabel *m_pArriConst;
    QLabel *m_pArriVar;
    QLabel *m_pTypeConst;
    QLabel *m_pTypeVar;
    QLabel *m_pMoneyConst;
    QLabel *m_pMoneyVar;
    QLabel *m_pTimeConst;
    QLabel *m_pTimeVar;

    // ****** 队列信息提示变量 ******
    QLabel *m_pNextConst;
    QLabel *m_pNextVar;
    QLabel *m_pfQueueNumConst;
    QLabel *m_pfQueueNumVar;
    QLabel *m_psQueueNumConst;
    QLabel *m_psQueueNumVar;
    QLabel *m_pCurMoneyConst;
    QLabel *m_pCurMoneyVar;
    QLabel *m_pSumCusConst;
    QLabel *m_pSumCusVar;
    QLabel *m_pAverageConst;
    QLabel *m_pAverageVar;
    // ****** 华丽的分割线 ******
    QLabel *m_pMoreCusTips;
    QLabel *m_pCusTips;
    QLabel *m_pBorderLabel;

    // ****** 以下是后台数据处理变量 ******
private:
     CServerType *m_pServer;
     myQueue<CCustomerType> *m_pCusQueue;
     myQueue<CCustomerType> *m_pCusQueueWait;
     int m_number;
     int m_nextCounter;

     // ****** 区间信息 ******
     int m_proLess;
     int m_proMore;
     int m_nextLess;
     int m_nextMore;
     int m_moneyLess;
     int m_moneyMore;
     // ****** 当前处理队列标记 ******
     int m_tags;
     // ****** 当前客户的前一客户完成交易时的总额 ******
     money_t m_preMoney;
     money_t m_totalMoney;
     // ****** 以上是后台数据处理变量 ******
private:
    QWidget *m_pParent;
};

#endif // CONTROLWIN_H
