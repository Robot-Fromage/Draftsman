/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.Node.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Definition of DraftsmanGUI Node class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <DGTypes>


#include <QGraphicsItem>


namespace DraftsmanCore { class Node; }


namespace DraftsmanGUI {


class Node : public QGraphicsItem
{
    typedef  QGraphicsItem  tSuperClass;
    typedef  Node           tSelf;

public:
    // Construction / Destruction
    virtual  ~Node();
    Node( tSuperClass* iParent = NULL );

public:
    // Mandatory Overrides
    virtual  QRectF  boundingRect() const override;
    virtual  void  paint( QPainter* painter, const  QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR )  override;

public:
    // Node GUI API
    QSizeF Size();
    QString Name();
    QString UUID();

private:
    // Private Data Members
    ::DraftsmanCore::Node* mNode;
    QSizeF mSize;

};


} // namespace DraftsmanGUI
