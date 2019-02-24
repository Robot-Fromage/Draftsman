/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.Graph.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanGUI Graph class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanGUI/DraftsmanGUI.Graph.hpp"


#include "DraftsmanGUI/DraftsmanGUI.Config.hpp"
#include "DraftsmanGUI/DraftsmanGUI.Node.hpp"
#include "__private__/DraftsmanGUI.__private__.GraphScene.hpp"
#include "__private__/DraftsmanGUI.__private__.GraphView.hpp"


#include <DCGraph>


#ifdef DRAFTSMANGUI_GRAPH_WITH_QOPENGLWIDGET
#include <QOpenGLWidget>
#endif


namespace DraftsmanGUI {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


Graph::~Graph()
{
    Destroy();
}


Graph::Graph( QWidget* iParent ) :
    tSuperClass( iParent ),
    mGraph( NULL ),
    mView(  NULL ),
    mScene( NULL )
{
    Init();
    Build();
    Compose();
}


//--------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------- Event


void
Graph::resizeEvent( QResizeEvent* event )
{
    tSuperClass::resizeEvent( event );
    Compose();
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------------------ GUI utilities


void
Graph::Init()
{
    mGraph  = new ::DC::Graph();
    mView   = new ::DraftsmanGUI::__private__::GraphView();
    mScene  = new ::DraftsmanGUI::__private__::GraphScene();
}


void
Graph::Build()
{
    setObjectName( "Draftsman_GUI_Graph" );

#ifdef DRAFTSMANGUI_GRAPH_WITH_QOPENGLWIDGET
    mView->update();
    QOpenGLWidget* gl = new QOpenGLWidget;
    QSurfaceFormat fmt;
    fmt.setSamples( 8 );
    gl->setFormat(fmt);
    mView->setViewport(gl);
    mView->setViewportUpdateMode( QGraphicsView::SmartViewportUpdate );
    mView->setRenderHint(QPainter::Antialiasing);
    mView->setAttribute(Qt::WA_OpaquePaintEvent);
    mView->setAttribute(Qt::WA_NoSystemBackground);
    mView->viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    mView->viewport()->setAttribute(Qt::WA_NoSystemBackground);
#endif

    mView->setParent( this );
    mView->setScene( mScene );
    mView->InitScroller();

    // TMP LEAK NODE
    auto testnode = new ::DraftsmanGUI::Node();
    testnode->setPos( mView->sceneRect().center() );
    mScene->addItem( testnode );
}


void
Graph::Compose()
{
    int w = width();
    int h = height();
    mView->resize( w, h );
}


void
Graph::Destroy()
{
    delete mScene;
    delete mView;
    delete mGraph;
}


} // namespace  DraftsmanGUI
