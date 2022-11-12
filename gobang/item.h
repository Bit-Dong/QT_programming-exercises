#ifndef ITEM_H
#define ITEM_H

#include <QPoint>

class Item
{
public:
    Item();
    Item(QPoint pt,bool bBlack);//棋子类的有参构造
    QPoint m_pt;//棋子坐标
    //重写==
    bool operator ==(const Item &t1) const
    {
        return (m_bBlack == t1.m_bBlack && m_pt == t1.m_pt);
    }
    bool m_bBlack;//是黑方还是白方下棋
};

#endif // ITEM_H

