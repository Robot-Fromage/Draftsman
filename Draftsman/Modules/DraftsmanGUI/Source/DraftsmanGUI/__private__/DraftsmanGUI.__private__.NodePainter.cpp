/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.NodePainter.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Implementation  of DraftsmanGUI NodePainter private class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "__private__/DraftsmanGUI.__private__.NodePainter.hpp"


#include <QPainter>
#include <QImage>
#include <QApplication>


#include "DraftsmanGUI/DraftsmanGUI.Config.hpp"
#include "DraftsmanGUI/DraftsmanGUI.Node.hpp"


#define  DEFAULT_DROPSHADOW_ACTUAL_TILESIZE     30
#define  DEFAULT_DROPSHADOW_INSET               20
#define  DEFAULT_DROPSHADOW_PAINT_SIZE          30
#define  DEFAULT_DROPSHADOW_OFFSET_X            2
#define  DEFAULT_DROPSHADOW_OFFSET_Y            4
#define  DEFAULT_DROPSHADOW_OFFSET              QPoint( DEFAULT_DROPSHADOW_OFFSET_X, DEFAULT_DROPSHADOW_OFFSET_Y )
#define  DEFAULT_DROPSHADOW_MARGIN_LEFT         0
#define  DEFAULT_DROPSHADOW_MARGIN_TOP          0
#define  DEFAULT_DROPSHADOW_MARGIN_RIGHT        0
#define  DEFAULT_DROPSHADOW_MARGIN_BOT          0
#define  DEFAULT_DROPSHADOW_MARGIN              QMargins( DEFAULT_DROPSHADOW_MARGIN_LEFT, DEFAULT_DROPSHADOW_MARGIN_TOP, DEFAULT_DROPSHADOW_MARGIN_RIGHT, DEFAULT_DROPSHADOW_MARGIN_BOT )
#define  DEFAULT_DROPSHADOW_OPACITY             0.4f

#define  DEFAULT_NODE_PADDING                   5
#define  DEFAULT_NODE_CAPTION_HEIGHT            20
#define  DEFAULT_NODE_MIN_BODY_HEIGHT           20
#define  DEFAULT_NODE_MIN_WIDTH                 100
#define  DEFAULT_NODE_MIN_HEIGHT                40


namespace DraftsmanGUI {
namespace __private__ {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


NodePainter::~NodePainter()
{
    DestroyInternalResources();
}


NodePainter::NodePainter() :
    mDrawCount( 0 ),

    mDropShadow_TopLeft(    NULL ),
    mDropShadow_Top(        NULL ),
    mDropShadow_TopRight(   NULL ),
    mDropShadow_Right(      NULL ),
    mDropShadow_BotRight(   NULL ),
    mDropShadow_Bot(        NULL ),
    mDropShadow_BotLeft(    NULL ),
    mDropShadow_Left(       NULL ),
    mDropShadow_Middle(     NULL ),

    mDropShadowActualTileSize(  DEFAULT_DROPSHADOW_ACTUAL_TILESIZE ),
    mDropShadowInset(           DEFAULT_DROPSHADOW_INSET ),
    mDropShadowPaintSize(       DEFAULT_DROPSHADOW_PAINT_SIZE ),
    mDropShadowOffset(          DEFAULT_DROPSHADOW_OFFSET ),
    mDropShadowMargins(         DEFAULT_DROPSHADOW_MARGIN ),
    mDropShadowOpacity(         DEFAULT_DROPSHADOW_OPACITY ),

    mPadding(                   DEFAULT_NODE_PADDING ),
    mCaptionHeight(             DEFAULT_NODE_CAPTION_HEIGHT ),
    mMinBodyHeight(             DEFAULT_NODE_MIN_BODY_HEIGHT ),
    mMinWidth(                  DEFAULT_NODE_MIN_WIDTH ),
    mMinHeight(                 DEFAULT_NODE_MIN_HEIGHT )
{
    InitInternalResources();
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------ Static Singleton accessor


//static
NodePainter*
NodePainter::Get()
{
    static  NodePainter*  sNodePainter = nullptr;
    if( !sNodePainter )
        sNodePainter = new NodePainter();

    return sNodePainter;
}


//--------------------------------------------------------------------------------------
//---------------------------------------------------------------------- Paint Functions


void
NodePainter::paint( ::DraftsmanGUI::Node* iNode, QPainter* iPainter )
{
    QSizeF s = iNode->boundingRect().size();
    int w = s.width();
    int h = s.height();

    int drop_shadow_x_corner_left   = 0;
    int drop_shadow_y_corner_top    = 0;
    int drop_shadow_x_corner_right  = w - mDropShadowPaintSize;
    int drop_shadow_y_corner_bot    = h - mDropShadowPaintSize;
    QPoint drop_shadow_top_left_corner(     drop_shadow_x_corner_left,  drop_shadow_y_corner_top );
    QPoint drop_shadow_top_right_corner(    drop_shadow_x_corner_right, drop_shadow_y_corner_top );
    QPoint drop_shadow_bot_left_corner(     drop_shadow_x_corner_left,  drop_shadow_y_corner_bot );
    QPoint drop_shadow_bot_right_corner(    drop_shadow_x_corner_right, drop_shadow_y_corner_bot );
    QSize  drop_shadow_paint_size( mDropShadowPaintSize, mDropShadowPaintSize );
    int dropShadowPaintSize2 = mDropShadowPaintSize * 2;
    QRect left_drop_shadow_rect(    drop_shadow_x_corner_left,
                                    mDropShadowPaintSize,
                                    mDropShadowPaintSize,
                                    h - dropShadowPaintSize2 );
    QRect top_drop_shadow_rect(     mDropShadowPaintSize,
                                    drop_shadow_y_corner_top,
                                    w - dropShadowPaintSize2,
                                    mDropShadowPaintSize );
    QRect right_drop_shadow_rect(   w - mDropShadowPaintSize,
                                    mDropShadowPaintSize,
                                    mDropShadowPaintSize,
                                    h - dropShadowPaintSize2 );
    QRect bot_drop_shadow_rect(     mDropShadowPaintSize,
                                    h - mDropShadowPaintSize,
                                    w - dropShadowPaintSize2,
                                    mDropShadowPaintSize );

    iPainter->setOpacity( mDropShadowOpacity );
    iPainter->setRenderHint( QPainter::RenderHint::SmoothPixmapTransform, true );
    iPainter->drawImage( QRect( drop_shadow_top_left_corner, drop_shadow_paint_size ),  *mDropShadow_TopLeft    );
    iPainter->drawImage( QRect( drop_shadow_top_right_corner, drop_shadow_paint_size ), *mDropShadow_TopRight   );
    iPainter->drawImage( QRect( drop_shadow_bot_left_corner, drop_shadow_paint_size ),  *mDropShadow_BotLeft    );
    iPainter->drawImage( QRect( drop_shadow_bot_right_corner, drop_shadow_paint_size ), *mDropShadow_BotRight   );
    iPainter->drawImage( QRect( left_drop_shadow_rect ),    *mDropShadow_Left   );
    iPainter->drawImage( QRect( top_drop_shadow_rect ),     *mDropShadow_Top    );
    iPainter->drawImage( QRect( right_drop_shadow_rect ),   *mDropShadow_Right  );
    iPainter->drawImage( QRect( bot_drop_shadow_rect ),     *mDropShadow_Bot    );
    iPainter->drawImage( QRect( mDropShadowPaintSize, mDropShadowPaintSize, w - dropShadowPaintSize2, h - dropShadowPaintSize2 ), *mDropShadow_Middle );
    iPainter->setOpacity( 1 );

    float node_x_corner_left  = mDropShadowMargins.left()   + 0.5f;
    float node_y_corner_top   = mDropShadowMargins.top()    + 0.5f;
    QPointF node_top_left_corner( node_x_corner_left, node_y_corner_top );
    //int node_x_corner_right = w - mDropShadowMargins.right();
    //int node_y_corner_bot   = h - mDropShadowMargins.bottom();

    iPainter->setRenderHint( QPainter::Antialiasing, true );

    QLinearGradient gradient( 0, 0, 0, iNode->Size().height() / 2 );
    gradient.setColorAt( 0, QColor( 45, 47, 45, 170 ) );
    gradient.setColorAt( 1, QColor( 10, 13, 10, 180 ) );
    iPainter->setBrush( gradient );
    iPainter->setPen( QColor( 0, 1, 0 ) );
    int border_radius = 10;
    iPainter->drawRoundedRect( QRectF( node_top_left_corner, iNode->Size() ), border_radius, border_radius);

    gradient = QLinearGradient( 0, 0, iNode->Size().width(), 0 );
    gradient.setColorAt( 0, QColor( 194, 28, 31, 255 ) );
    gradient.setColorAt( 1, QColor( 194, 28, 31, 20 ) );
    iPainter->setBrush( gradient );
    iPainter->setPen( Qt::NoPen );
    QPainterPath path;
    path.addRoundedRect( QRectF( node_top_left_corner + QPoint( 1, 1 ), QSize( iNode->Size().width() - 2, mCaptionHeight - 2 ) ), border_radius, border_radius );
    QPainterPath path2;
    path2.addRect( node_x_corner_left + 1, node_y_corner_top + mCaptionHeight / 2, iNode->Size().width() - 2, mCaptionHeight / 2 );
    iPainter->drawPath( path + path2 );

    gradient = QLinearGradient( node_x_corner_left + 10, 0, node_x_corner_left + iNode->Size().width() - 20, 0 );
    gradient.setColorAt( 0, QColor( 255, 255, 255, 0 ) );
    gradient.setColorAt( 0.5, QColor( 255, 255, 255, 127 ) );
    gradient.setColorAt( 1, QColor( 255, 255, 255, 0 ) );
    iPainter->setBrush( Qt::NoBrush );
    iPainter->setPen( QPen( gradient, 1 ) );
    iPainter->drawLine( node_x_corner_left + 10, node_y_corner_top + 2,  node_x_corner_left + iNode->Size().width() - 20, node_y_corner_top + 2 );

    iPainter->setBrush( QColor( 0, 0, 0, 127 ) );
    iPainter->setPen( Qt::NoPen );
    iPainter->drawRect( node_x_corner_left + 1, node_y_corner_top + 2 + mCaptionHeight, iNode->Size().width() - 1, mCaptionHeight );

    iPainter->setPen( Qt::white );
    iPainter->drawText( node_top_left_corner + QPointF( mPadding, mCaptionHeight - ( GetTextMetricsHeight() / 2 ) ), iNode->Name() );
    iPainter->drawText( node_top_left_corner + QPointF( mPadding, 2 * mCaptionHeight - ( GetTextMetricsHeight() / 2 ) ), iNode->UUID() );


    ++mDrawCount;
    return;
}


//--------------------------------------------------------------------------------------
//-------------------------------------------------------------------- Getters / Setters


int64_t
NodePainter::GetDrawCount()
{
    return  mDrawCount;
}


//--------------------------------------------------------------------------------------
//-------------------------------------------------------------------- Getters / Setters


int
NodePainter::GetTextMetricsWidth( const  QString&  iStr )
{
    auto fm = QApplication::fontMetrics();
    return  fm.width( iStr );
}


int
NodePainter::GetTextMetricsHeight()
{
    auto fm = QApplication::fontMetrics();
    return  fm.height();
}


int
NodePainter::GetPadding()
{
    return  mPadding;
}


int
NodePainter::GetCaptionHeight()
{
    return  mCaptionHeight;
}


int
NodePainter::GetMinBodyHeight()
{
    return  mMinBodyHeight;
}


int
NodePainter::GetMinWidth()
{
    return  mMinWidth;
}


int
NodePainter::GetMinHeight()
{
    return  mMinHeight;
}


const  QMargins&
NodePainter::GetDropShadowMargins()
{
    return  mDropShadowMargins;
}


//--------------------------------------------------------------------------------------
//--------------------------------------------------------- Internal Resource Management


void
NodePainter::InitInternalResources()
{
    QString respath = QString::fromStdString( ::DraftsmanGUI::Config::GetResourcePath() );
    mDropShadow_TopLeft     = new QImage( respath + "media/img/graph/node/dropshadow/top_left.png" );
    mDropShadow_Top         = new QImage( respath + "media/img/graph/node/dropshadow/top.png" );
    mDropShadow_TopRight    = new QImage( respath + "media/img/graph/node/dropshadow/top_right.png" );
    mDropShadow_Right       = new QImage( respath + "media/img/graph/node/dropshadow/right.png" );
    mDropShadow_BotRight    = new QImage( respath + "media/img/graph/node/dropshadow/bot_right.png" );
    mDropShadow_Bot         = new QImage( respath + "media/img/graph/node/dropshadow/bot.png" );
    mDropShadow_BotLeft     = new QImage( respath + "media/img/graph/node/dropshadow/bot_left.png" );
    mDropShadow_Left        = new QImage( respath + "media/img/graph/node/dropshadow/left.png" );
    mDropShadow_Middle      = new QImage( respath + "media/img/graph/node/dropshadow/middle.png" );

    RecomputeNodeMetrics();
}


void
NodePainter::DestroyInternalResources()
{
    delete  mDropShadow_TopLeft;
    delete  mDropShadow_Top;
    delete  mDropShadow_TopRight;
    delete  mDropShadow_Right;
    delete  mDropShadow_BotRight;
    delete  mDropShadow_Bot;
    delete  mDropShadow_BotLeft;
    delete  mDropShadow_Left;
    delete  mDropShadow_Middle;
}


void
NodePainter::RecomputeNodeMetrics()
{
    // Assuming square and all the same.
    mDropShadowActualTileSize = mDropShadow_TopLeft->width();
    mDropShadowMargins = QMargins(  mDropShadowPaintSize - ( mDropShadowInset + mDropShadowOffset.x() ),
                                    mDropShadowPaintSize - ( mDropShadowInset + mDropShadowOffset.y() ),
                                    ( mDropShadowPaintSize - mDropShadowInset ) + mDropShadowOffset.x(),
                                    ( mDropShadowPaintSize - mDropShadowInset ) + mDropShadowOffset.y() );
}


} // namespace __private__
} // namespace DraftsmanGUI
