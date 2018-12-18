/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.Config.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Implementation of DraftsmanGUI Config private module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "__private__/DraftsmanGUI.__private__.Config.hpp"


#define  DEFAULT_CONFIG_RESOURCE_PATH           "resources/"
#define  DEFAULT_CONFIG_STYLE_DIR_RELATIVE_PATH "media/css/"
#define  DEFAULT_CONFIG_STYLE_FILE_NAME         "DraftsmanGUI_Style.qss"


namespace DraftsmanGUI {
namespace __private__ {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


Config::~Config()
{
}


Config::Config() :
    mResourcePath(          DEFAULT_CONFIG_RESOURCE_PATH ),
    mStyleDirRelativePath(  DEFAULT_CONFIG_STYLE_DIR_RELATIVE_PATH ),
    mStyleFileName(         DEFAULT_CONFIG_STYLE_FILE_NAME )
{
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------ Static Singleton accessor


//static
Config*
Config::Get()
{
    static  Config*  sConfig = __nullptr;
    if( !sConfig )
        sConfig = new Config();

    return sConfig;
}


//--------------------------------------------------------------------------------------
//-------------------------------------------------------------------- Getters / Setters


const  std::string&
Config::GetResourcePath()
{
    return  mResourcePath;
}


void
Config::SetResourcePath( const  std::string&  iStr )
{
    mResourcePath = iStr;
}


const  std::string&
Config::GetStyleDirRelativePath()
{
    return  mStyleDirRelativePath;
}


void
Config::SetStyleDirRelativePath( const  std::string&  iStr )
{
    mStyleDirRelativePath = iStr;
}


const  std::string&
Config::GetStyleFileName()
{
    return  mStyleFileName;
}


void
Config::SetStyleFileName( const  std::string&  iStr )
{
    mStyleFileName = iStr;
}


} // namespace __private__
} // namespace DraftsmanGUI
