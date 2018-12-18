/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.GraphView.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Definition of DraftsmanGUI GraphView private class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <QGraphicsView>


#include "__private__/DraftsmanGUI.__private__.ForwardQProperty.hpp"


class  QScroller;
class  QTimer;
class  QCursor;


namespace DraftsmanGUI {
namespace __private__ {


class GraphView : public QGraphicsView
{
    Q_OBJECT

    Q_PROPERTY( QColor BackgroundColor READ getBackgroundColor WRITE setBackgroundColor )
    Q_PROPERTY( QColor GridColor READ getGridColor WRITE setGridColor )
    Q_PROPERTY( QColor SubGridColor READ getSubGridColor WRITE setSubGridColor )
    Q_PROPERTY( int GridSize READ getGridSize WRITE setGridSize )
    Q_PROPERTY( int SubGridCount READ getSubGridCount WRITE setSubGridCount )

    FORWARD_QPROPERTY( QColor, BackgroundColor )
    FORWARD_QPROPERTY( QColor, GridColor )
    FORWARD_QPROPERTY( QColor, SubGridColor )
    FORWARD_QPROPERTY( int, GridSize )
    FORWARD_QPROPERTY( int, SubGridCount )

    typedef  QGraphicsView  tSuperClass;
    typedef  GraphView      tSelf;

public:
    // Construction / Destruction
    virtual  ~GraphView();
    GraphView( QWidget* iParent = NULL );

protected:
    // Protected Painting Behaviour Overrides
    virtual void drawBackground(QPainter *painter, const QRectF &rect) override;
    virtual void drawForeground(QPainter *painter, const QRectF &rect) override;

protected:
    // Protected Event Overrids
    virtual  void  keyPressEvent( QKeyEvent*  event )           override;
    virtual  void  keyReleaseEvent( QKeyEvent*  event )         override;
    virtual  void  mouseMoveEvent( QMouseEvent*  event )        override;
    virtual  void  mousePressEvent( QMouseEvent*  event )       override;
    virtual  void  mouseReleaseEvent( QMouseEvent*  event )     override;
    virtual  void  wheelEvent( QWheelEvent*  event )            override;

private:
    // Tick slot
    Q_SLOT void tickEvent();

private:
    // Delegate Drawing Functions
    void  drawGrid( QPainter* painter, const QRectF &rect, const QColor& iGridColor, const QColor& iSubGridColor, int iGridSize, int iSubGridCount);

private:
    // Custom Interaction Behaviours
    qreal   Scale();
    void    DeltaScale( qreal iDelta );
    void    SetScale( qreal iValue );

private:
    // GUI utilities
    void  Init();
    void  Build();
    void  Compose();
    void  Destroy();

public:
    // Scroller Patch
    void  InitScroller();

private:
    // Private Data Members
    QScroller*  mScroller;
    QTimer*     mTimer;
    QCursor*    mLensCursor;

    bool        mMoveModifierOn;
    bool        mZoomModifierOn;
    bool        mRightButtonMoveOn;
    bool        mMiddleButtonMoveOn;

    bool        mMouseMovedWhileMouseZoom;

    QString     mInteractionState;
    QString     mLastInteractionState;
    QPoint      mLastMousePos;
    QPoint      mTargetViewPos;
    QPointF     mTargetScenePos;

    QImage*     mVignette_TopLeft;
    QImage*     mVignette_Top;
    QImage*     mVignette_TopRight;
    QImage*     mVignette_Right;
    QImage*     mVignette_BotRight;
    QImage*     mVignette_Bot;
    QImage*     mVignette_BotLeft;
    QImage*     mVignette_Left;
};


} // namespace __private__
} // namespace DraftsmanGUI
