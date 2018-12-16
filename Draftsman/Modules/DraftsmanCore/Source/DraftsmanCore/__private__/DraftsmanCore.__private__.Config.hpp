/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.__private__.Config.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Definition of DraftsmanCore Config private module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <string>


namespace DraftsmanCore {
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

private:
    // Private Data members*
    std::string  mResourcePath;

};


} // namespace __private__
} // namespace DraftsmanCore
