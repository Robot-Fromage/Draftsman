/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.GraphScene.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Implementation of DraftsmanGUI GraphScene private class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "__private__/DraftsmanGUI.__private__.GraphScene.hpp"


#include <QPainter>


namespace DraftsmanGUI {
namespace __private__ {


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


} // namespace __private__
} // namespace DraftsmanGUI
