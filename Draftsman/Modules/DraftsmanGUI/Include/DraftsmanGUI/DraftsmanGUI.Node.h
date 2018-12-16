/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.Node.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once


#include <QGraphicsItem>


#include "Draftsman.GUI.Config.h"


#ifdef DRAFTSMAN_GUI_NODE_WITH_QGRAPHICSDROPSHADOWEFFECT
class QGraphicsDropShadowEffect;
#endif


namespace  Draftsman { namespace  Core { class Node; } }


namespace  Draftsman {
namespace  GUI {


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
    ::Draftsman::Core::Node* mNode;
    QSizeF mSize;

#ifdef DRAFTSMAN_GUI_NODE_WITH_QGRAPHICSDROPSHADOWEFFECT
    QGraphicsDropShadowEffect* mEffect;
#endif
};


} // namespace  GUI
} // namespace  Draftsman
