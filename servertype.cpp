
// Author : Jammg
// Built in : 2015/5/27

#include <cstdlib>
#include "servertype.h"

CServerType::CServerType(
                        ServerStatus state,
                        time_t withdrawl,
                        time_t deposit,
                        time_t borrow,
                        time_t refund)
                        : m_pCustomer(NULL) , m_totalMoney(-1) , m_workTime(-1) , m_cusSumPro(0) , m_allTimePro(0)
{
    m_remainTime = -1;
    m_processTime = -1;
    m_state = state;
    m_isTimeDefByServer = false;
    setBusinessTime(withdrawl , deposit , borrow , refund);
}

CServerType::~CServerType()
{
    delete m_pCustomer;
}

ServerStatus CServerType::isFree() const
{
    return m_state;
}

void CServerType::setBusy()
{
    m_state = BUSY;
}

void CServerType::setFree()
{
    m_state = FREE;
}

void CServerType::setNewCustomer(const CCustomerType &cust)
{
    if( m_pCustomer )
    {
        free(m_pCustomer);
        m_pCustomer = NULL;
    }
    CCustomerType *tmp;
    tmp = (CCustomerType *)malloc( sizeof(CCustomerType ) );
    if( tmp == NULL )
        std::cerr << "Occur exception when malloc memory." << std::endl;
    m_pCustomer = tmp;
    // ...
    m_pCustomer -> operator=( cust );

    if( m_pCustomer -> getWaitingTime() == -1 )
        m_cusSumPro ++;

}

void CServerType::setWorkTime(time_t worktime)
{
    m_workTime = worktime;
}

void CServerType::setTotalMoney(money_t money)
{
    m_totalMoney = money;
}

void CServerType::setProcessTimeByServer()
{
    m_isTimeDefByServer = true;
}

void CServerType::setProcessTime()
{
    if(m_pCustomer)
    {
        Business tmp;
        tmp = m_pCustomer -> getBusiType();
        if( m_isTimeDefByServer )
        {
            if( tmp == WITHDRAWL )
                m_processTime = m_withdrawlTime;
            else if( tmp == DEPOSIT )
                m_processTime = m_depositTime;
            else if ( tmp == BORROW )
                m_processTime = m_borrowTime;
            else
                m_processTime = m_refundTime;
        }
        else
        {
            m_processTime = m_pCustomer -> getProcessTime();
        }
        m_remainTime = m_processTime;
        m_allTimePro += m_processTime;
    }
}


void CServerType::setBusinessTime(time_t withdrawl,
                                 time_t deposit,
                                 time_t borrow,
                                 time_t refund )
{
    m_withdrawlTime = withdrawl;
    m_depositTime = deposit;
    m_borrowTime = borrow;
    m_refundTime = refund;
}

void CServerType::subProcessTime()
{
    if( m_remainTime != 0 )
        --m_remainTime;
    // Current customer's service be finished
//    if( m_remainTime == 0 )
//    {
//        // reinitial server
//        this -> setFree();
//        m_remainTime = 0;
//    }
    //reInit();
}

void CServerType::subWorkTime()
{
    if( m_workTime != -1 )
        -- m_workTime;
}

void CServerType::reInitCusInfo()
{
    //m_isTimeDefByServer = false;

    delete m_pCustomer;
    m_pCustomer = NULL;
    m_state = FREE;
    m_processTime = 0;
    m_remainTime = 0;

}

bool CServerType::isHadCustomer()
{
    return !(m_pCustomer == NULL);
}

void CServerType::setCurCustWaitTime()
{
    if(m_pCustomer)
    {
        time_t arri;
        time_t cur;
        int wait;
        arri = m_pCustomer -> getArrivalTime() + m_pCustomer -> getWaitingTime();
        cur = time(NULL);
        wait = cur - arri;
        m_allTimePro += wait;
        m_pCustomer -> setWaitingTime( wait );
    }
}

void CServerType::renewMoney()
{
    if(m_pCustomer)
    {
        switch(m_pCustomer -> getBusiType())
        {
        case WITHDRAWL:
        case BORROW:
            m_totalMoney -= m_pCustomer -> getProcessMoney();
            break;
        case DEPOSIT:
        case REFUND:
            m_totalMoney += m_pCustomer -> getProcessMoney();
            break;
        default:
            break;
        }
    }
}

money_t CServerType::getTotalMoney() const
{
    return m_totalMoney;
}

time_t CServerType::getRemainTime() const
{
    return m_remainTime;
}

const CCustomerType& CServerType::getCurCust() const
{
    return *m_pCustomer;
}

int CServerType::getCurCustNumb() const
{
    if(m_pCustomer)
        return m_pCustomer -> getCustomerNumber();
    return -1;
}

time_t CServerType::getCurCustArriTime() const
{
    if(m_pCustomer)
        return m_pCustomer -> getArrivalTime();
    return 0;
}

time_t CServerType::getCurCustWaitTime() const
{
    if(m_pCustomer)
        return m_pCustomer -> getWaitingTime();
    return 0;
}

time_t CServerType::getCurCustProcTime() const
{
    return m_processTime;
}

time_t CServerType::getRemainWorkTime() const
{
    return m_workTime;
}


int CServerType::getCusSumPro() const
{
    return m_cusSumPro;
}

time_t CServerType::getAllTimePro() const
{
    return m_allTimePro;
}

void CServerType::subRemaining()
{
    m_allTimePro = m_allTimePro - m_remainTime;
}


















