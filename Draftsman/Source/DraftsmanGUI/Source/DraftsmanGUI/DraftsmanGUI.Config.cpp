/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.Config.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanGUI Config module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanGUI/DraftsmanGUI.Config.hpp"


#include "__private__/DraftsmanGUI.__private__.Config.hpp"


#include <DCConfig>


namespace DraftsmanGUI {
namespace Config {


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
    return  ::DC::Config::version_number();
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


const  std::string&
GetResourcePath()
{
    return  ::DraftsmanGUI::__private__::Config::Get()->GetResourcePath();
}

const  std::string&
GetStyleDirRelativePath()
{
    return  ::DraftsmanGUI::__private__::Config::Get()->GetStyleDirRelativePath();
}


const  std::string&
GetStyleFileName()
{
    return  ::DraftsmanGUI::__private__::Config::Get()->GetStyleFileName();
}


std::string
GetStyleFilePath()
{
    return  GetResourcePath() + GetStyleDirRelativePath() + GetStyleFileName();
}


void
SetResourcePath( const  std::string&  iStr )
{
    ::DraftsmanGUI::__private__::Config::Get()->SetResourcePath( iStr );
}


void
SetStyleDirRelativePath( const  std::string&  iStr )
{
    ::DraftsmanGUI::__private__::Config::Get()->SetStyleDirRelativePath( iStr );
}


void
SetStyleFileName( const  std::string&  iStr )
{
    ::DraftsmanGUI::__private__::Config::Get()->SetStyleFileName( iStr );
}


} // namespace Config
} // namespace DraftsmanGUI
