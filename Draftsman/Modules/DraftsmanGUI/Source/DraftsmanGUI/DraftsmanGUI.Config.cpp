/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.Config.cpp
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#include "Draftsman.GUI.Config.h"


#include "__private__/Draftsman.GUI.__private__.Config.h"


#include <DraftsmanCoreConfig>


namespace  Draftsman {
namespace  GUI {
namespace  Config {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------------- Public Define Config


const  int
gui_version_number()
{
    return  DRAFSTMAN_GUI_VERSION_NUMBER;
}


const  int
core_version_number()
{
    return  ::Draftsman::Core::Config::version_number();
}


const  bool
with_opengl_context()
{
#ifdef DRAFTSMAN_GUI_GRAPH_WITH_QOPENGLWIDGET
    return  true;
#else
    return  false;
#endif
}


//--------------------------------------------------------------------------------------
//---------------------------------------------------------------- Private Tampon Config


// Get
const  std::string&
GetResourcePath()
{
    return  ::Draftsman::GUI::__private__::Config::Get()->GetResourcePath();
}

const  std::string&
GetStyleDirRelativePath()
{
    return  ::Draftsman::GUI::__private__::Config::Get()->GetStyleDirRelativePath();
}


const  std::string&
GetStyleFileName()
{
    return  ::Draftsman::GUI::__private__::Config::Get()->GetStyleFileName();
}


std::string
GetStyleFilePath()
{
    return  GetResourcePath() + GetStyleDirRelativePath() + GetStyleFileName();
}


// Set
void
SetResourcePath( const  std::string&  iStr )
{
    ::Draftsman::GUI::__private__::Config::Get()->SetResourcePath( iStr );
}


void
SetStyleDirRelativePath( const  std::string&  iStr )
{
    ::Draftsman::GUI::__private__::Config::Get()->SetStyleDirRelativePath( iStr );
}


void
SetStyleFileName( const  std::string&  iStr )
{
    ::Draftsman::GUI::__private__::Config::Get()->SetStyleFileName( iStr );
}


} // namespace  Config
} // namespace  GUI
} // namespace  Draftsman

