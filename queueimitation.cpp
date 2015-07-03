#include "queueimitation.h"

CQueueImitation::CQueueImitation(QWidget *parent)
    :QMainWindow(parent),
      m_pBankScene(new QGraphicsScene(this)),
      m_pBankView(new QGraphicsView(m_pBankScene , this)),
      m_pParent(parent)
{
    initWidget();
}

CQueueImitation::~CQueueImitation()
{

}

void CQueueImitation::initWidget()
{
    QPalette pale;
    pale.setColor(QPalette::Base , QColor(67,90,120));
    m_pBankView -> setPalette(pale);
//    m_pBankScene -> setSceneRect(0,0,m_pBankView -> width() , m_pBankView -> height());
//    m_pBankView -> fitInView(0,0,m_pBankView -> width() , m_pBankView -> height());

    m_pBankMoney = new QLabel(this);
    m_pBankMoney -> show();


    this -> setCentralWidget(m_pBankView);
    m_pBankView -> show();

    this-> setStyleSheet("QScrollBar:horizontal{height:12px;border:1px solid black;border-color:black;\
                                                margin:0px,0px,0px,0px;padding-left:10px;padding-right:10px;}\
                        QScrollBar::handle:horizontal{height:16px;min-width:20;background:#232329;\
                                                border:1px solid #525252;}\
                        QScrollBar::handle:horizontal::disabled{background:#232329;}\
                        QScrollBar::handle:horizontal:hover{background:#232329;border:1px solid #E0E0E0;}\
                        QScrollBar::add-line:horizontal{width:10px;background:#121215;subcontrol-position:right;}\
                        QScrollBar::sub-line:horizontal{width:10px;background:#121215;subcontrol-position:left;}\
                        QScrollBar::add-page:horizontal{background:#454551;}\
                        QScrollBar::sub-page:horizontal{background:#454551;}\
                        QScrollBar::up-arrow:horizontal{border-width:1px;max-height:16px;min-width:17px;}\
                        QScrollBar::down-arrow:horizontal{border-style:outset;border-width:1px;}\
                        QScrollBar::down-arrow:horizontal:hover{border-style:outset;border-width:2px;border:1px solid #E0E0E0;}"
                        "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"\
                        "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"\
                        "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%); border-radius:4px;min-height:20;}"\
                        "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/images/a/2.png);subcontrol-position:bottom;}"\
                        "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/images/a/2.png);subcontrol-position:top;}"\
                        "QScrollBar::add-line:vertical:hover{height:9px;width:8px;border-image:url(:/images/a/2.png);subcontrol-position:bottom;}"\
                        "QScrollBar::sub-line:vertical:hover{height:9px;width:8px;border-image:url(:/images/a/2.png);subcontrol-position:top;}"\
                        "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}"\
                        );

}

