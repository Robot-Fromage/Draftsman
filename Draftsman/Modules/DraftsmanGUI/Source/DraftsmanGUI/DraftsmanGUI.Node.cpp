/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.Node.cpp
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#include "Draftsman.GUI.Node.h"


#ifdef DRAFTSMAN_GUI_NODE_WITH_QGRAPHICSDROPSHADOWEFFECT
#include <QGraphicsDropShadowEffect>
#endif


#include "DraftsmanCoreNode"


#include "__private__/Draftsman.GUI.__private__.NodePainter.h"


#define  DEFAULT_WIDTH      100.f
#define  DEFAULT_HEIGHT     50.f
#define  DEFAULT_SIZE       QSizeF( DEFAULT_WIDTH, DEFAULT_HEIGHT )


namespace  Draftsman {
namespace  GUI {


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
#ifdef DRAFTSMAN_GUI_NODE_WITH_QGRAPHICSDROPSHADOWEFFECT
    mEffect = new QGraphicsDropShadowEffect();
    mEffect->setBlurRadius( 10 );
    mEffect->setOffset( 5, 5 );
    mEffect->setColor( QColor( 0, 0, 0, 160 ) );
    setGraphicsEffect( mEffect );
#endif

    mNode = new  ::Draftsman::Core::Node();
    int ch  = ::Draftsman::GUI::__private__::NodePainter::Get()->GetCaptionHeight();
    int uh  = ::Draftsman::GUI::__private__::NodePainter::Get()->GetTextMetricsHeight();
    int p   = ::Draftsman::GUI::__private__::NodePainter::Get()->GetPadding();
    int bh  = ::Draftsman::GUI::__private__::NodePainter::Get()->GetMinBodyHeight();
    int imw = ::Draftsman::GUI::__private__::NodePainter::Get()->GetTextMetricsWidth( UUID() );

    int w = imw + p * 2;
    int h = ch + uh + bh + p * 2;
    mSize = QSize( w, h );
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------------ Mandatory Overrides


QRectF
Node::boundingRect() const
{
    const  QMargins&  m = ::Draftsman::GUI::__private__::NodePainter::Get()->GetDropShadowMargins();
    auto rectsize = mSize + QSize( m.left() + m.right(), m.top() + m.bottom() );
    return  QRectF( QPointF(), rectsize );
}


void
Node::paint( QPainter* painter, const  QStyleOptionGraphicsItem* option, QWidget* widget )
{
    ::Draftsman::GUI::__private__::NodePainter::Get()->paint( this, painter );
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


} // namespace  GUI
} // namespace  Draftsman

