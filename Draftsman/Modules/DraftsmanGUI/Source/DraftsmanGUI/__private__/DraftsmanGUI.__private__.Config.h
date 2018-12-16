/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.__private__.Config.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once


#include <string>


namespace  Draftsman {
namespace  GUI {
namespace  __private__ {


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


} // namespace  __private__
} // namespace  GUI
} // namespace  Draftsman
