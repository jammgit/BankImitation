#include "controlwin.h"

//WITHDRAWL , DEPOSIT , BORROW , REFUND
QString Busi[4] = {{"WITHDRAWL"},{"DEPOSIT"},{"BORROW"},{"REFUND"}};

CControlWin::CControlWin(QWidget *parent)
    :QMainWindow(parent),
      m_pParent(parent)
{
    initWidget();
    initConnect();
    m_number = 1;
    m_tags = 1;
}

CControlWin::~CControlWin()
{

}

void CControlWin::initWidget()
{
    //this -> setStyleSheet("background-color:rgb(255,255,255);");
    // set right widget window's layout
    QPalette pale;
    pale.setColor(QPalette::Text , Qt::black);

    m_pCenWidget = new QWidget();
    this -> setCentralWidget(m_pCenWidget);
    m_pWidgetLayout = new QGridLayout;
    m_pCenWidget -> setLayout(m_pWidgetLayout);

    m_pMoneyLine = new QLineEdit();
    //m_pMoneyLine ->setPlaceholderText("请输入总金额");
    m_pMoneyLine -> setText("400");
    m_pMoneyLabel = new QLabel("Bank Money(0<YUAN)");
    m_pMoneyLabel -> setPalette(pale);
    m_pWidgetLayout -> addWidget(m_pMoneyLine , 1 , 3 , 1 , 2);
    m_pWidgetLayout -> addWidget(m_pMoneyLabel , 1 , 1 , 1 , 2);
    m_pMoneyLabel -> setAlignment(Qt::AlignCenter);

    m_pWorkTimeLine = new QLineEdit();
    //m_pWorkTimeLine -> setPlaceholderText("请输入时间");
    m_pWorkTimeLine -> setText("10");
    m_pWorkTimeLabel = new QLabel("Busi Time(0<HH<24)");
    m_pWorkTimeLabel -> setPalette(pale);
    m_pWidgetLayout -> addWidget(m_pWorkTimeLine , 2 , 3 , 1 , 2);
    m_pWorkTimeLabel -> setAlignment(Qt::AlignCenter);
    m_pWidgetLayout -> addWidget(m_pWorkTimeLabel , 2 , 1 , 1 , 2);

    tmp = new QLabel("---------<---------");
    tmp -> setPalette(pale);
    tmp -> setAlignment(Qt::AlignCenter);
    m_pFreLineLess = new QLineEdit();
    m_pFreLineMore = new QLineEdit();
    //m_pFreLineLess -> setPlaceholderText("0");
    m_pFreLineLess -> setText("5");
    //m_pFreLineMore -> setPlaceholderText("1");
    m_pFreLineMore -> setText("10");
    m_pFreLabel = new QLabel("Arrive (SS)");
    m_pFreLabel -> setPalette(pale);
    m_pWidgetLayout -> addWidget(m_pFreLineLess , 3 , 2 , 1 , 1);
    m_pWidgetLayout -> addWidget(tmp , 3 , 3 , 1 , 1);
    m_pWidgetLayout -> addWidget(m_pFreLineMore , 3 , 4 , 1 , 1);
    m_pWidgetLayout -> addWidget(m_pFreLabel , 3 , 1 , 1 , 1);

    tmp = new QLabel("---------<---------");
    tmp -> setPalette(pale);
    tmp -> setAlignment(Qt::AlignCenter);
    m_pProTimeLineLess = new QLineEdit();
    m_pProTimeLineMore = new QLineEdit();
    //m_pProTimeLineLess -> setPlaceholderText("0");
    m_pProTimeLineLess -> setText("5");
    //m_pProTimeLineMore -> setPlaceholderText("1");
    m_pProTimeLineMore -> setText("10");
    m_pProTimeLabel = new QLabel("Proce (SS)");
    m_pProTimeLabel -> setPalette(pale);
    m_pWidgetLayout -> addWidget(m_pProTimeLineLess , 4 , 2 , 1 , 1);
    m_pWidgetLayout -> addWidget(tmp , 4 , 3 , 1 , 1);
    m_pWidgetLayout -> addWidget(m_pProTimeLineMore , 4 , 4 , 1 , 1);
    m_pWidgetLayout -> addWidget(m_pProTimeLabel , 4 , 1 , 1 , 1);

    tmp = new QLabel("---------<---------");
    tmp -> setPalette(pale);
    tmp -> setAlignment(Qt::AlignCenter);
    m_pCusMoneyLineLess = new QLineEdit();
    m_pCusMoneyLineMore = new QLineEdit();
    //m_pCusMoneyLineLess -> setPlaceholderText("0");
    m_pCusMoneyLineLess -> setText("500");
    //m_pCusMoneyLineMore -> setPlaceholderText("1");
    m_pCusMoneyLineMore -> setText("1000");
    m_pCusMoneyLabel = new QLabel("Trade (Y)");
    m_pCusMoneyLabel -> setPalette(pale);
    m_pWidgetLayout -> addWidget(m_pCusMoneyLineLess , 5 , 2 , 1 , 1);
    m_pWidgetLayout -> addWidget(tmp , 5 , 3 , 1 , 1);
    m_pWidgetLayout -> addWidget(m_pCusMoneyLineMore , 5 , 4 , 1 , 1);
    m_pWidgetLayout -> addWidget(m_pCusMoneyLabel , 5 , 1 , 1 , 1);

    m_pStartBtn = new QPushButton("Start imitate");
    m_pStopBtn = new QPushButton("Stop imitate");
    m_pWidgetLayout -> addWidget(m_pStartBtn , 6 , 1 , 1 , 2);
    m_pWidgetLayout -> addWidget(m_pStopBtn , 6 , 3 , 1 , 2);

    m_pBorderLabel = new QLabel("—————————————|—————————————");
    m_pBorderLabel -> setPalette(pale);
    m_pBorderLabel -> setAlignment(Qt::AlignCenter);
    m_pMoreCusTips = new QLabel("Other Cus info");
    m_pMoreCusTips -> setPalette(pale);
    m_pMoreCusTips -> setAlignment(Qt::AlignCenter);
    m_pCusTips = new QLabel("Current Cus info");
    m_pCusTips -> setPalette(pale);
    m_pCusTips -> setAlignment(Qt::AlignCenter);

    m_pNumConst = new QLabel("Cus number:");
    m_pNumConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pNumVar = new QLabel("NONE");
    m_pNumVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pArriConst = new QLabel("Arriving time:");
    m_pArriConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pArriVar = new QLabel("NONE");
    m_pArriVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pTypeConst = new QLabel("Trade type:");
    m_pTypeConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pTypeVar = new QLabel("NONE");
    m_pTypeVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pMoneyConst = new QLabel("Trade amount:");
    m_pMoneyConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pMoneyVar = new QLabel("NONE");
    m_pMoneyVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pTimeConst = new QLabel("Trade time:");
    m_pTimeConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pTimeVar = new QLabel("NONE");
    m_pTimeVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_pNumConst -> setPalette(pale);
    m_pNumVar -> setPalette(pale);
    m_pArriConst -> setPalette(pale);
    m_pArriVar -> setPalette(pale);
    m_pTypeConst -> setPalette(pale);
    m_pTypeVar -> setPalette(pale);
    m_pMoneyConst -> setPalette(pale);
    m_pMoneyVar -> setPalette(pale);
    m_pTimeConst -> setPalette(pale);
    m_pTimeVar -> setPalette(pale);

    m_pNextConst = new QLabel("Next arrival Time:");
    m_pNextConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pNextVar = new QLabel("NONE");
    m_pNextVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pfQueueNumConst = new QLabel("First queue:");
    m_pfQueueNumConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pfQueueNumVar = new QLabel("NONE");
    m_pfQueueNumVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_psQueueNumConst = new QLabel("Second queue:");
    m_psQueueNumConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_psQueueNumVar = new QLabel("NONE");
    m_psQueueNumVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pCurMoneyConst = new QLabel("Bank's Money:");
    m_pCurMoneyConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pCurMoneyVar = new QLabel("NONE");
    m_pCurMoneyVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pSumCusConst = new QLabel("Cus sum:");
    m_pSumCusConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pSumCusVar = new QLabel("NONE");
    m_pSumCusVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pAverageConst = new QLabel("Average time:");
    m_pAverageConst -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pAverageVar = new QLabel("NONE");
    m_pAverageVar -> setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_pNextConst -> setPalette(pale);
    m_pNextVar -> setPalette(pale);
    m_pfQueueNumConst -> setPalette(pale);
    m_pfQueueNumVar -> setPalette(pale);
    m_psQueueNumConst -> setPalette(pale);
    m_psQueueNumVar -> setPalette(pale);
    m_pCurMoneyConst -> setPalette(pale);
    m_pCurMoneyVar -> setPalette(pale);
    m_pAverageConst -> setPalette(pale);
    m_pAverageVar -> setPalette(pale);
    m_pSumCusConst -> setPalette(pale);
    m_pSumCusVar -> setPalette(pale);

    m_pWidgetLayout -> addWidget( m_pBorderLabel ,8,1,1,4);
    m_pWidgetLayout -> addWidget( m_pCusTips ,7,3,1,2);
    m_pWidgetLayout -> addWidget( m_pMoreCusTips ,7,1,1,2);

    m_pWidgetLayout -> addWidget( m_pNumConst ,9,3,1,2);
    m_pWidgetLayout -> addWidget( m_pNumVar ,10,3,1,2);
    m_pWidgetLayout -> addWidget( m_pArriConst ,11,3,1,2);
    m_pWidgetLayout -> addWidget( m_pArriVar ,12,3,1,2);
    m_pWidgetLayout -> addWidget( m_pTypeConst ,13,3,1,2);
    m_pWidgetLayout -> addWidget( m_pTypeVar ,14,3,1,2);
    m_pWidgetLayout -> addWidget( m_pMoneyConst ,15,3,1,2);
    m_pWidgetLayout -> addWidget( m_pMoneyVar ,16,3,1,2);
    m_pWidgetLayout -> addWidget( m_pTimeConst ,17,3,1,2);
    m_pWidgetLayout -> addWidget( m_pTimeVar ,18,3,1,2);

    m_pWidgetLayout -> addWidget( m_pfQueueNumConst ,9,1,1,2);
    m_pWidgetLayout -> addWidget( m_pfQueueNumVar ,10,1,1,2);
    m_pWidgetLayout -> addWidget( m_psQueueNumConst ,11,1,1,2);
    m_pWidgetLayout -> addWidget( m_psQueueNumVar ,12,1,1,2);
    m_pWidgetLayout -> addWidget( m_pNextConst ,13,1,1,2);
    m_pWidgetLayout -> addWidget( m_pNextVar ,14,1,1,2);
    m_pWidgetLayout -> addWidget( m_pCurMoneyConst ,15,1,1,2);
    m_pWidgetLayout -> addWidget( m_pCurMoneyVar ,16,1,1,2);
    m_pWidgetLayout -> addWidget( m_pSumCusConst ,17,1,1,2);
    m_pWidgetLayout -> addWidget( m_pSumCusVar ,18,1,1,2);
    m_pWidgetLayout -> addWidget( m_pAverageConst ,19,1,1,2);
    m_pWidgetLayout -> addWidget( m_pAverageVar ,20,1,1,2);
}

void CControlWin::initConnect()
{
    m_pTimer = new QTimer(this);
    //update()会自动产生重绘消息，调用paintEvent()
    QObject::connect(m_pTimer, SIGNAL(timeout()), this, SLOT(renewInfo()));
    QObject::connect(m_pStartBtn , SIGNAL(clicked()) , this ,SLOT(myStart()));
    QObject::connect(m_pStopBtn , SIGNAL(clicked()) , this , SLOT(myStop()));
}

void CControlWin::myStart()
{
    if(!inputInfoCorrect())
    {
        // message box ...
        QMessageBox::information(this,
                                 "错误信息","数据输入有误!");
        return ;
    }
    srand((unsigned)time(NULL));
    m_nextLess = m_pFreLineLess->text().toInt();
    m_nextMore = m_pFreLineMore->text().toInt();
    m_proLess = m_pProTimeLineLess->text().toInt();
    m_proMore = m_pProTimeLineMore->text().toInt();
    m_moneyLess = m_pCusMoneyLineLess->text().toInt();
    m_moneyMore = m_pCusMoneyLineMore->text().toInt();

    m_nextCounter = rand()%(m_nextMore - m_nextLess) + m_nextLess + 1;

    time_t timetmp = time(NULL);
    timetmp+=(time_t)m_nextCounter;
    //time(&timetmp);
    char *p = ctime(&timetmp);
    p[20]='\0';
    m_pNextVar -> setText(QString(p+11));

    // 服务器数据初始化
    m_pServer = new CServerType();
    m_pServer -> setTotalMoney((money_t)m_pMoneyLine -> text().toInt());
    m_totalMoney = (money_t)m_pMoneyLine -> text().toInt();
    m_pCurMoneyVar -> setText(m_pMoneyLine -> text());
    m_pServer -> setWorkTime((time_t)m_pWorkTimeLine -> text().toInt() * 3600);
    //m_pBankMoney -> setText(m_pMoneyLine -> text());
    m_pAverageVar -> setText("NONE");
    m_pSumCusVar -> setText("NONE");
    // 队列初始化
    m_pCusQueue = new myQueue<CCustomerType>;
    m_pCusQueueWait = new myQueue<CCustomerType>;
    //std::cout << "This is after start timer"<< std::endl;
    m_pTimer -> start(1000);

}

void CControlWin::myStop()
{
    m_pTimer -> stop();
    this -> reInitInfo();
}

void CControlWin::renewInfo()
{
    // 计算并存储到达客户的信息 和 下一客户到达信息
    m_pServer -> subWorkTime();
    if( m_pServer -> getRemainWorkTime() != 0 )
    {
        m_nextCounter--;
        if( m_nextCounter == 0 )
        {
            CCustomerType customer(this -> randomBusi() ,
                                     m_number ,
                                     time(NULL) ,
                                     (time_t)(this -> randomProcessTime()),
                                     (money_t)(this -> randomCusMoney()));

            m_pCusQueue -> push_back(customer);
            this -> renewQueueInfo();
            // 下一客户号 ，到达时间间隔
            m_number ++;
            m_nextCounter = this -> randomNextCustomer();

            time_t timetmp = time(NULL);
            timetmp += (time_t)m_nextCounter;
            //time(&timetmp);
            char *p = ctime(&timetmp);
            p[20]='\0';
            m_pNextVar -> setText(QString(p+11));

        }

        // 下一个交易客户
        this -> renewServerCus();

        m_pServer -> subProcessTime();
        // 交易完成，更新银行信息
        if(m_pServer -> isHadCustomer() && m_pServer -> getRemainTime() == 0 )
        {
            // 如果当前用户是还款，那么需要去检索第二个队列，查找能满足的客户并交易
            if( m_pServer -> getCurCust().getBusiType() == DEPOSIT
                    || m_pServer -> getCurCust().getBusiType() == REFUND )
            {
                m_tags = 2;
                m_preMoney = m_pServer -> getTotalMoney();
            }
            m_pServer -> setFree();
            m_pServer -> renewMoney();
            m_pServer -> reInitCusInfo();
            QString str = QString::number(m_pServer -> getTotalMoney() , 10);
            m_pCurMoneyVar -> setText(str);
            // total money less than the total when the last customer who DEPOSIT or REFUND
            if( m_pServer -> getTotalMoney() <= m_preMoney )
                m_tags = 1;
            this -> setCusTipWait();
        }
    }
    else
    {
        m_pTimer -> stop();
        this -> reInitInfo();
    }

//    static int i = 0;
//    m_pBankScene -> addLine(10,10 + i*2,100 +i,100);
//    m_pBankScene -> addRect(1,1,100,100);
//    i+=2;
//    QGraphicsItem *ball = new QGraphicsEllipseItem(0, 0, 20, 20);


//    QTimeLine *timer = new QTimeLine(5000);
//    timer->setFrameRange(0, 100);

//    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
//    animation->setItem(ball);
//    animation->setTimeLine(timer);

//    for (int i = 600; i > 0; --i)
//        animation->setPosAt(i / 600.0, QPointF(i, 60));
//    m_pBankScene -> addItem(ball);
//    timer -> start();

}

void CControlWin::renewServerCus()
{
    switch(m_tags)
    {
    case 1:
        if( m_pServer -> isFree() == FREE && !m_pCusQueue->isEmpty())
        {
            CCustomerType cus = m_pCusQueue->front();
            // 查找银行能满足的客户
            while((cus.getBusiType() == WITHDRAWL || cus.getBusiType() == BORROW)
                    && cus.getProcessMoney() > m_pServer -> getTotalMoney()//m_preMoney //-> text().toUInt()
                    && !m_pCusQueue->isEmpty() )
            {
                m_pCusQueueWait -> push_back(m_pCusQueue->pop_front());
                if( m_pCusQueue->isEmpty() )
                    break;
                cus = m_pCusQueue->front();
            }

            if(!m_pCusQueue->isEmpty())
            {
                m_pServer -> setNewCustomer(m_pCusQueue -> pop_front());
                m_pServer -> setBusy();
                m_pServer -> setCurCustWaitTime();
                m_pServer -> setProcessTime();
                renewCurCusLabelInfo();
            }
            this -> renewQueueInfo();
        }
        break;
    case 2:
        if( m_pServer -> isFree() && !m_pCusQueueWait -> isEmpty())
        {
            int counter = 0;
            CCustomerType cus;
            while( counter <= m_pCusQueueWait -> length() )
            {
                cus = m_pCusQueueWait -> front();
                if( cus.getProcessMoney() > m_pServer -> getTotalMoney() )
                {
                    m_pCusQueueWait -> change_front_to_back();
                }
                else
                {
                    m_pServer -> setNewCustomer(m_pCusQueueWait -> pop_front());
                    m_pServer -> setBusy();
                    m_pServer -> setCurCustWaitTime();
                    m_pServer -> setProcessTime();
                    renewCurCusLabelInfo();
                    this -> renewQueueInfo();
                    break;
                }
                counter++;
            }
            if( counter > m_pCusQueueWait -> length() )
                m_tags = 1;
        }
        else m_tags = 1;
        break;

    default:
        break;
    }

}

void CControlWin::renewCurCusLabelInfo()
{
    const CCustomerType &cus = m_pServer -> getCurCust();
    char str[20];
    sprintf(str , "%d" , cus.getCustomerNumber());
    m_pNumVar -> setText(str);
    m_pArriVar -> setText(cus.getQTime().toString());
    m_pTypeVar -> setText(Busi[cus.getBusiType() - 1]);
    sprintf(str , "%d" , cus.getProcessMoney());
    m_pMoneyVar -> setText(QString(str));
    sprintf(str , "%d" , (int)m_pServer -> getRemainTime());
    m_pTimeVar -> setText(QString(str));
}

void CControlWin::renewQueueInfo()
{

    char str[20];
    sprintf(str , "%d" , m_pCusQueue->length());
    m_pfQueueNumVar -> setText(QString(str));
    sprintf(str , "%d" , m_pCusQueueWait ->length());
    m_psQueueNumVar -> setText(QString(str));
}

void CControlWin::setCusTipWait()
{
    m_pNumVar -> setText("NONE");
    m_pArriVar -> setText("NONE");
    m_pTypeVar -> setText("NONE");
    m_pMoneyVar -> setText("NONE");
    m_pTimeVar -> setText("NONE");
}

bool CControlWin::inputInfoCorrect()
{
    if(m_pWorkTimeLine -> text().isEmpty() || m_pWorkTimeLine -> text().toInt() <= 0)
        return false;
    if(m_pMoneyLine ->text().toInt() < 0 || m_pMoneyLine ->text().isEmpty() )
        return false;
    if(m_pFreLineLess ->text().toInt() < 0 || m_pFreLineMore -> text().toInt() < 0
            || m_pFreLineLess ->text().toInt() >= m_pFreLineMore -> text().toInt())
        return false;
    if(m_pProTimeLineLess ->text().toInt() < 0 || m_pProTimeLineMore -> text().toInt() < 0
            || m_pProTimeLineMore ->text().toInt() <= m_pProTimeLineLess -> text().toInt())
        return false;
    if(m_pCusMoneyLineLess ->text().toInt() < 0 || m_pCusMoneyLineMore -> text().toInt() < 0
            || m_pCusMoneyLineMore ->text().toInt() <= m_pCusMoneyLineLess -> text().toInt())
        return false;

    return true;
}

void CControlWin::outputAverageTime()
{
    if(m_pServer)
    {
        time_t sumtime = 0;
        int sumcus = 0;
        if( !m_pServer -> isFree() )
        {
            m_pServer -> subRemaining();
        }
        while( !m_pCusQueue -> isEmpty() )
        {
            m_pServer -> setNewCustomer( m_pCusQueue -> pop_front() );
            m_pServer -> setCurCustWaitTime();
        }
        while( !m_pCusQueueWait -> isEmpty() )
        {
            m_pServer -> setNewCustomer( m_pCusQueueWait -> pop_front() );
            m_pServer -> setCurCustWaitTime();
        }
        sumtime = m_pServer -> getAllTimePro();
        sumcus = m_pServer -> getCusSumPro();
        QString time;
        if(sumcus != 0)
            time = QString::number(time_t(sumtime / sumcus) , 10);
        else time.insert(0,"0");
        m_pSumCusVar -> setText(QString::number(sumcus , 10));
        m_pAverageVar -> setText(time + " Sec");
    }
}

void CControlWin::reInitInfo()
{
    // output average remaining time per customer
    this -> outputAverageTime();

    this -> setCusTipWait();
    m_pfQueueNumVar -> setText("NONE");
    m_psQueueNumVar -> setText("NONE");
    m_pNextVar -> setText("NONE");
    m_pCurMoneyVar -> setText("NONE");
    //m_pAverageVar -> setText("NONE");
    m_number = 1;

    if(m_pServer)
    {
        delete m_pServer;
        delete m_pCusQueue;
        delete m_pCusQueueWait;
        m_pServer = NULL;
        m_pCusQueue = NULL;
        m_pCusQueueWait = NULL;
    }

}

// random function
time_t CControlWin::randomProcessTime()
{
    return (time_t)(rand()%(m_proMore - m_proLess) + m_proLess + 1);
}

int CControlWin::randomNextCustomer()
{
    return rand()%(m_nextMore - m_nextLess) + m_nextLess + 1;
}

money_t CControlWin::randomCusMoney()
{
    return rand()%(m_moneyMore - m_moneyLess) + m_moneyLess + 1;
}

Business CControlWin::randomBusi()
{
    srand((unsigned)time(NULL));
    int tmp = rand()%4 + 1;
    switch(tmp)
    {
        case 1:
            return WITHDRAWL;
        case 2:
            return DEPOSIT;
        case 3:
            return BORROW;
        case 4:
            return REFUND;
        default:
            return NONE;
    }
}

