/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.__private__.Config.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanCore Config private module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanCore.__private__.Config.hpp"


#define  DEFAULT_CONFIG_RESOURCE_PATH   "resources/"


namespace DraftsmanCore {
namespace __private__ {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


Config::~Config()
{
}


Config::Config() :
    mResourcePath( DEFAULT_CONFIG_RESOURCE_PATH )
{
}


//--------------------------------------------------------------------------------------
//------------------------------------------------------------ Static Singleton accessor


//static
Config*
Config::Get()
{
    static  Config*  sConfig = nullptr;
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


} // namespace __private__
} // namespace DraftsmanCore
