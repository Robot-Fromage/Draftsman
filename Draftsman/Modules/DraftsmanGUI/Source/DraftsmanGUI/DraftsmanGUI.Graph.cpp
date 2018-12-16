/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.Graph.cpp
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#include "Draftsman.GUI.Graph.h"


#include "DraftsmanCoreGraph"
#include "__private__/Draftsman.GUI.__private__.GraphScene.h"
#include "__private__/Draftsman.GUI.__private__.GraphView.h"
#include "Draftsman.GUI.Config.h"


//TMP:
#include "Draftsman.GUI.Node.h"


#ifdef DRAFTSMAN_GUI_GRAPH_WITH_QOPENGLWIDGET
#include <QOpenGLWidget>
#endif


namespace  Draftsman {
namespace  GUI {


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
    mGraph  = new ::Draftsman::Core::Graph();
    mView   = new ::Draftsman::GUI::__private__::GraphView();
    mScene  = new ::Draftsman::GUI::__private__::GraphScene();
}


void
Graph::Build()
{
    setObjectName( "Draftsman_GUI_Graph" );

#ifdef DRAFTSMAN_GUI_GRAPH_WITH_QOPENGLWIDGET
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

    // TMP LEAK
    auto testnode = new ::Draftsman::GUI::Node();
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


} // namespace  GUI
} // namespace  Draftsman

