/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.Node.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanGUI Node class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanGUI/DraftsmanGUI.Node.hpp"


#include "__private__/DraftsmanGUI.__private__.NodePainter.hpp"


#include <DCNode>


#define  DEFAULT_WIDTH      100.f
#define  DEFAULT_HEIGHT     50.f
#define  DEFAULT_SIZE       QSizeF( DEFAULT_WIDTH, DEFAULT_HEIGHT )


namespace  DraftsmanGUI {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


Node::~Node()
{
}


Node::Node( tSuperClass* iParent ) :
    tSuperClass( iParent ),
    mNode( NULL ),
    mSize( DEFAULT_SIZE )
{
    mNode = new  ::DC::Node();
    int ch  = ::DraftsmanGUI::__private__::NodePainter::Get()->GetCaptionHeight();
    int uh  = ::DraftsmanGUI::__private__::NodePainter::Get()->GetTextMetricsHeight();
    int pv  = ::DraftsmanGUI::__private__::NodePainter::Get()->GetPadding();
    int bh  = ::DraftsmanGUI::__private__::NodePainter::Get()->GetMinBodyHeight();
    int mw  = ::DraftsmanGUI::__private__::NodePainter::Get()->GetTextMetricsWidth( UUID() );

    int w = mw + pv * 2;
    int h = ch + uh + bh + pv * 2;
    mSize = QSize( w, h );
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------------ Mandatory Overrides


QRectF
Node::boundingRect() const
{
    const  QMargins&  m = ::DraftsmanGUI::__private__::NodePainter::Get()->GetDropShadowMargins();
    auto rectsize = mSize + QSize( m.left() + m.right(), m.top() + m.bottom() );
    return  QRectF( QPointF(), rectsize );
}


void
Node::paint( QPainter* painter, const  QStyleOptionGraphicsItem* option, QWidget* widget )
{
    ::DraftsmanGUI::__private__::NodePainter::Get()->paint( this, painter );
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------------------- Node GUI API


QSizeF
Node::Size()
{
    return  mSize;
}


QString
Node::Name()
{
    return  QString::fromStdString( mNode->GetName() );
}


QString
Node::UUID()
{
    return  QString::fromStdString( mNode->GetUUID() );
}


} // namespace DraftsmanGUI
