// Author : Jammg
// Built in : 2015/5/28

#ifndef __myQueue__
#define __myQueue__

#include <iostream>
#include <cstdlib>

template <class Type>
class myQueue;

template <class Type>
class myQueue
{
public:
    typedef struct
    {
        Type data;
        struct myQueue<Type>::element *next;
    }element, *pElement;

    myQueue();
    ~myQueue();

    myQueue(const myQueue<Type> &source);
    const myQueue<Type> &operator=(const myQueue<Type> &source);

    const myQueue<Type>::element * getFrontPointer() const;

    const myQueue<Type>::element * getBackPointer() const;

    bool isEmpty() const;

    int length() const;

    void reInit();

    void destroy();

    Type front() const;

    Type back() const;

    Type pop_front();

    void push_back(const Type &source);

    void change_front_to_back();

    void deletemyQueue();

    void addmyQueue();

private:
    void myFree(myQueue<Type>::element *source);
    void *myMalloc(unsigned int size);

private:
    myQueue<Type>::element *m_pTypeFront;
    myQueue<Type>::element *m_pTypeBack;
    int m_length;
};

template <class Type>
myQueue<Type>::myQueue(): m_pTypeFront(NULL) ,m_pTypeBack(NULL) ,  m_length(0)
{
}

template <class Type>
myQueue<Type>::~myQueue()
{
    this -> destroy();
}

template <class Type>
myQueue<Type>::myQueue(const myQueue<Type> &source)
{
    this -> operator=(source);
}

template <class Type>
const myQueue<Type> & myQueue<Type>::operator=(const myQueue<Type> &source)
{
    int counter = 0;
    //myQueue<Type> tmp;
    const myQueue<Type>::element *ptmp;
    myQueue<Type>::element *pmytmp = m_pTypeFront;
    myQueue<Type>::element *pmal = NULL;

    if( source.isEmpty() )
    {
        this -> destroy();
    }
    else
    {
        ptmp = source.getFrontPointer();
        while( ptmp != NULL )
        {
            if(pmytmp == NULL)
            {
                pmytmp = (myQueue<Type>::pElement)myMalloc(sizeof(myQueue<Type>::element));
                pmytmp -> next = NULL;
                m_pTypeFront = pmytmp;
                m_pTypeBack = pmytmp;
            }
            pmytmp -> data = ptmp -> data;
            counter ++;
            if(ptmp -> next != NULL && pmytmp == m_pTypeBack )
            {
                pmal = (myQueue<Type>::pElement)myMalloc(sizeof(myQueue<Type>::element));
                pmal -> next = NULL;
                pmytmp -> next = pmal;
                m_pTypeBack = pmal;
                pmytmp = pmytmp -> next;
            }
            ptmp = ptmp -> next;
        }
        m_pTypeBack = pmytmp;
        pmytmp = pmytmp -> next;
        m_pTypeBack -> next = NULL;
        this -> myFree(pmytmp);
    }
    m_length = counter;
}

template <class Type>
void myQueue<Type>::myFree(myQueue<Type>::element *source)
{
    myQueue<Type>::element *pmytmp = source;
    while(source)
    {
        source = source -> next;
        free(pmytmp);
        pmytmp = source;
    }
}

template <class Type>
const struct myQueue<Type>::element * myQueue<Type>::getFrontPointer() const
{
    return m_pTypeFront;
}

template <class Type>
const struct myQueue<Type>::element * myQueue<Type>::getBackPointer() const
{
    return m_pTypeBack;
}

template <class Type>
bool myQueue<Type>::isEmpty() const
{
    return (m_length == 0);
}

template <class Type>
int myQueue<Type>::length() const
{
    return m_length;
}

template <class Type>
void myQueue<Type>::reInit()
{
    this -> destroy();
    m_pTypeBack = NULL;
    m_pTypeFront = NULL;
    m_length = 0;
}

template <class Type>
void myQueue<Type>::destroy()
{
    myQueue<Type>::element *tmp;
    while( m_pTypeFront != NULL )
    {
        tmp = m_pTypeFront;
        m_pTypeFront = m_pTypeFront -> next;
        free(tmp);
    }
    m_pTypeBack = NULL;
    m_length = 0;
}

template <class Type>
Type myQueue<Type>::pop_front()
{
    myQueue<Type>::element *ptmp;
    Type tmp;
    if( m_pTypeFront == NULL )
    {
        std::cerr << "myQueue is empty when get first element." << std::endl;
        exit(0);
    }
    tmp = m_pTypeFront -> data;
    ptmp = m_pTypeFront;
    m_pTypeFront = m_pTypeFront -> next;

    if( NULL == m_pTypeFront )
    {
        m_pTypeBack = NULL;
        m_pTypeFront = NULL;
    }

    free(ptmp);
    m_length --;
    return tmp;
}

template <class Type>
void myQueue<Type>::push_back(const Type &source)
{
    myQueue<Type>::element *tmp;

    tmp = (myQueue<Type>::pElement)myMalloc(sizeof(element));
    tmp -> data = source;
    tmp -> next = NULL;

    if( this -> isEmpty() )
    {
        m_pTypeFront = tmp;
        m_pTypeBack = m_pTypeFront;
    }
    else
    {
        m_pTypeBack -> next = tmp;
        m_pTypeBack = m_pTypeBack -> next;
    }
    m_length ++;
}

template<class type>
void myQueue<type>::change_front_to_back()
{
    if( this -> isEmpty() )
    {
        std::cerr << "Queue is empty ." << std::endl;
        exit(0);
    }
    if( this -> length() != 1 )
    {
        myQueue<type>::pElement tmp;
        tmp = m_pTypeFront;
        m_pTypeFront = tmp -> next;
        tmp -> next = NULL;
        m_pTypeBack -> next = tmp;
        m_pTypeBack = m_pTypeBack -> next;
    }

}

template <class Type>
Type myQueue<Type>::front() const
{
    if( this -> isEmpty() )
    {
        std::cerr << "Queue is empty ." << std::endl;
        exit(0);
    }
    return m_pTypeFront -> data;
}

template <class Type>
Type myQueue<Type>::back() const
{
    if( this -> isEmpty() )
    {
        std::cerr << "Queue is empty ." << std::endl;
        exit(0);
    }
    return m_pTypeBack -> data;
}

template <class Type>
void *myQueue<Type>::myMalloc(unsigned int size)
{
    void *ptmp;
    ptmp = malloc(size);
    if( ptmp == NULL )
    {
        std::cerr << "Occur exception when malloc memory ." << std::endl;
        exit(0);
    }
    return ptmp;
}



template <class Type>
void myQueue<Type>::deletemyQueue()
{

}

template <class Type>
void myQueue<Type>::addmyQueue()
{

}




#endif
