// Author : Jammg
// Built in : 2015/5/27

#include "customertype.h"

CCustomerType::CCustomerType(
                            Business busi,
                            int number ,
                            time_t arrival,
                            time_t process,
                            money_t money)
{
    m_QTime = QTime::currentTime();
    setCustomerInfo(busi , number , arrival , process , money);
    m_waitingTime = -1;
}

CCustomerType::CCustomerType(const CCustomerType &source)
{
    this -> operator=(source);
}

CCustomerType::~CCustomerType()
{

}

const CCustomerType& CCustomerType::operator=(const CCustomerType& source)
{
    m_busiType = source.m_busiType;
    m_customerNumber = source.m_customerNumber;
    m_waitingTime = source.m_waitingTime;
    m_processTime = source.m_processTime;
    m_arrivalTime = source.m_arrivalTime;
    m_processMoney = source.m_processMoney;
    m_QTime = source.m_QTime;
    return (*this);
}

void CCustomerType::setCustomerInfo(
                                    Business busi,
                                    int number,
                                    time_t arrival,
                                    time_t process,
                                    money_t money)
{
    m_busiType = busi;
    // Between two customer , there are least 1 second .
    // type int can hold it (in 600 minutes)
    m_customerNumber = number % 32767;
    m_arrivalTime = arrival;
    m_processTime = process;
    m_processMoney = money;
}

void CCustomerType::setWaitingTime(time_t waiting )
{
    m_waitingTime += waiting;
}

void CCustomerType::setProcessTime(time_t process )
{
    m_processTime = process;
}

time_t CCustomerType::getArrivalTime() const
{
    return m_arrivalTime;
}

Business CCustomerType::getBusiType() const
{
    return m_busiType;
}

int CCustomerType::getCustomerNumber() const
{
    return m_customerNumber;
}

time_t CCustomerType::getWaitingTime() const
{
    return m_waitingTime;
}

time_t CCustomerType::getProcessTime() const
{
    return m_processTime;
}

money_t CCustomerType::getProcessMoney() const
{
    return m_processMoney;
}

QTime CCustomerType::getQTime() const
{
    return m_QTime;
}







