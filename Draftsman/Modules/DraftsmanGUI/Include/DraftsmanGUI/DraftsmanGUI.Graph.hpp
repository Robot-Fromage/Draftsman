/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.Graph.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Definition of DraftsmanGUI Graph class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <DGTypes>


#include <QWidget>


#include "__private__/DraftsmanGUI.__private__.ForwardQProperty.hpp"


namespace DraftsmanCore { class Graph; }
namespace DraftsmanGUI { namespace __private__ { class GraphView; } }
namespace DraftsmanGUI { namespace __private__ { class GraphScene; } }


namespace DraftsmanGUI {


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
    ::DraftsmanCore::Graph* mGraph;

    ::DraftsmanGUI::__private__::GraphView*     mView;
    ::DraftsmanGUI::__private__::GraphScene*    mScene;

};


} // namespace  DraftsmanGUI
