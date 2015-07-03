// Author : Jammg
// Built in : 2015/5/27

#ifndef __SERVERTYPE__
#define __SERVERTYPE__

#include <iostream>
#include <ctime>
#include "customertype.h"

typedef enum
{
    BUSY , FREE
}ServerStatus;

class CServerType
{
public:
    CServerType(ServerStatus state = FREE ,
                time_t withdrawl = -1,
                time_t deposit = -1,
                time_t borrow = -1,
                time_t refund = -1);

    ~CServerType();

    ServerStatus isFree() const;

    void setBusy();

    void setFree();

    void setNewCustomer(const CCustomerType &cust);

    //d setTimeByCustomer();
    void setWorkTime(time_t worktime);

    void setTotalMoney(money_t money);

    void setProcessTime();
    // for every business , there are rules
    void setBusinessTime(time_t withdrawl,
                        time_t deposit,
                        time_t borrow,
                        time_t refund);

    void setProcessTimeByServer();

    void subProcessTime();

    void subWorkTime();

    void setCurCustWaitTime();

    void renewMoney();

    bool isHadCustomer();

    money_t getTotalMoney() const;
    // bool isCompleteDeal() const;

    // Server's remaining time for customer
    time_t getRemainTime() const;

    time_t getRemainWorkTime() const;
    // Customer's information
    const CCustomerType& getCurCust() const;

    int getCurCustNumb() const;

    time_t getCurCustArriTime() const;

    time_t getCurCustWaitTime() const;

    time_t getCurCustProcTime() const;

    int getCusSumPro() const;

    time_t getAllTimePro() const;

    void subRemaining();

    void reInitCusInfo();

private:
    bool m_isTimeDefByServer;

    CCustomerType *m_pCustomer;
    ServerStatus m_state;
    time_t m_processTime;
    time_t m_remainTime;
    money_t m_totalMoney;
    time_t m_workTime;

    int m_cusSumPro;
    time_t m_allTimePro;
    // WITHDRAWL , DEPOSIT , BORROW , REFUND
    time_t m_withdrawlTime;
    time_t m_depositTime;
    time_t m_borrowTime;
    time_t m_refundTime;
};


#endif


