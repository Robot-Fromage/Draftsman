/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.__private__.GraphScene.cpp
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#include "__private__/Draftsman.GUI.__private__.GraphScene.h"


#include <QPainter>


namespace  Draftsman {
namespace  GUI {
namespace  __private__ {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


GraphScene::~GraphScene()
{
}


GraphScene::GraphScene( QObject* iParent ) :
    tSuperClass( iParent )
{
    setObjectName( "DraftsmanGUIGraphScene" );
}


} // namespace  __private__
} // namespace  GUI
} // namespace  Draftsman

