/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.Graph.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once


#include <QWidget>


#include "__private__/Draftsman.GUI.__private__.ForwardQProperty.h"


namespace  Draftsman { namespace  Core { class Graph; } }
namespace  Draftsman { namespace  GUI { namespace __private__ { class GraphView; } } }
namespace  Draftsman { namespace  GUI { namespace __private__ { class GraphScene; } } }


namespace  Draftsman {
namespace  GUI {


class Graph : public QWidget
{
    Q_OBJECT

    typedef  QWidget    tSuperClass;
    typedef  Graph      tSelf;

public:
    // Construction / Destruction
    virtual  ~Graph();
    Graph( QWidget* iParent = NULL );

protected:
    // Event
    virtual  void  resizeEvent( QResizeEvent*   event )  override;

private:
    // GUI utilities
    void  Init();
    void  Build();
    void  Compose();
    void  Destroy();

private:
    // Private Data Members
    ::Draftsman::Core::Graph* mGraph;

    ::Draftsman::GUI::__private__::GraphView* mView;
    ::Draftsman::GUI::__private__::GraphScene* mScene;

};


} // namespace  GUI
} // namespace  Draftsman
