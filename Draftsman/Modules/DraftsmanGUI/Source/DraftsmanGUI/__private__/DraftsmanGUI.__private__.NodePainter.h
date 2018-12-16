/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.__private__.NodePainter.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once

#include <stdint.h>


class QPainter;
class QImage;


#include <QPoint>
#include <QSize>
#include <QMargins>


namespace Draftsman { namespace GUI { class Node; } }


namespace  Draftsman {
namespace  GUI {
namespace  __private__ {


class NodePainter
{
    typedef  NodePainter  tSelf;

private:
    // Construction / Destruction
    virtual  ~NodePainter();
    NodePainter();

public:
    // Static Singleton accessor
    static  NodePainter*  Get();

public:
    // Paint Functions
    void  paint( ::Draftsman::GUI::Node* iNode, QPainter* iPainter );

public:
    // Getters / Setters
    int64_t  GetDrawCount();
    int      GetTextMetricsWidth( const  QString&  iStr );
    int      GetTextMetricsHeight();
    int      GetPadding();
    int      GetCaptionHeight();
    int      GetMinBodyHeight();
    int      GetMinWidth();
    int      GetMinHeight();

    const  QMargins&  GetDropShadowMargins();

private:
    // Internal Resource Management
    void  InitInternalResources();
    void  DestroyInternalResources();
    void  RecomputeNodeMetrics();

private:
    // Private Data Members
    int64_t mDrawCount;

    QImage*     mDropShadow_TopLeft;
    QImage*     mDropShadow_Top;
    QImage*     mDropShadow_TopRight;
    QImage*     mDropShadow_Right;
    QImage*     mDropShadow_BotRight;
    QImage*     mDropShadow_Bot;
    QImage*     mDropShadow_BotLeft;
    QImage*     mDropShadow_Left;
    QImage*     mDropShadow_Middle;

    int         mDropShadowActualTileSize;  // Actual size of the drop shadow tile, assuming all the same
    int         mDropShadowInset;           // How the drop shadow tile is pushed in side contents
    int         mDropShadowPaintSize;       // Desired painting side of drop shadow tiles
    QPoint      mDropShadowOffset;          // Offset of drop shadow
    QMargins    mDropShadowMargins;         // Cached margins of drop shadow
    float       mDropShadowOpacity;         // Opacity of the drop shadow

    int         mPadding;
    int         mCaptionHeight;
    int         mMinBodyHeight;
    int         mMinWidth;
    int         mMinHeight;
};


} // namespace  __private__
} // namespace  GUI
} // namespace  Draftsman
