/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.Config.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Definition of DraftsmanGUI Config private module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <string>


namespace DraftsmanGUI {
namespace __private__ {


class Config
{
    typedef  Config  tSelf;

private:
    // Construction / Destruction
    virtual ~Config();
    Config();

public:
    // Static Singleton accessor
    static  Config*  Get();

public:
    // Getters / Setters
    const  std::string&  GetResourcePath();
    void  SetResourcePath( const  std::string&  iStr );

    const  std::string&  GetStyleDirRelativePath();
    void  SetStyleDirRelativePath( const  std::string&  iStr );

    const  std::string&  GetStyleFileName();
    void  SetStyleFileName( const  std::string&  iStr );

private:
    // Private Data members*
    std::string  mResourcePath;
    std::string  mStyleDirRelativePath;
    std::string  mStyleFileName;

};


} // namespace __private__
} // namespace DraftsmanGUI
