/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.__private__.GraphScene.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once


#include <QGraphicsScene>


#include "__private__/Draftsman.GUI.__private__.ForwardQProperty.h"


namespace  Draftsman {
namespace  GUI {
namespace  __private__ {


class GraphScene : public QGraphicsScene
{
    Q_OBJECT

    typedef  QGraphicsScene tSuperClass;
    typedef  GraphScene     tSelf;

public:
    // Construction / Destruction
    virtual  ~GraphScene();
    GraphScene( QObject* iParent = NULL );

};


} // namespace  __private__
} // namespace  GUI
} // namespace  Draftsman
