// Author : Jammg
// Built in : 2015/5/27

#ifndef __CUSTOMERTYPE__
#define __CUSTOMERTYPE__

#include <ctime>
#include <iostream>
#include <QTime>

#define money_t unsigned int

typedef enum
{
    NONE , WITHDRAWL , DEPOSIT , BORROW , REFUND  // 取款，存款，借款，还款
}Business;


class CCustomerType
{
public:
    CCustomerType(
                  Business busi = NONE,
                  int number = -1,
                  time_t arrival = 0,
                  time_t process = -1,
                  money_t money = 0
                  );
    // copy constructor
    CCustomerType(const CCustomerType &source);

    ~CCustomerType();

    const CCustomerType& operator=(const CCustomerType& source);

    // Set customer's information
    void setCustomerInfo(
                        Business busi,
                        int numner,
                        time_t arrival,
                        time_t process,
                        money_t money);
    // Set customer's waiting time
    void setWaitingTime(time_t waiting = -1);

    void setProcessTime(time_t process = -1);

    time_t getArrivalTime() const;

    Business getBusiType() const;

    int getCustomerNumber() const;

    time_t getWaitingTime() const;

    time_t getProcessTime() const;
    // add extra function ...
    money_t getProcessMoney() const;

    QTime getQTime() const;

private:
    Business m_busiType;
    // Business hours of bank is under 600 minutes , type 'int' can hold it
    int m_customerNumber;
    time_t m_waitingTime;
    time_t m_processTime;
    money_t m_processMoney;
    time_t m_arrivalTime;

    QTime m_QTime;

};







#endif
