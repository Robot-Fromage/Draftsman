/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.__private__.GenerateUUID.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanCore GenerateUUID private module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanCore.__private__.GenerateUUID.hpp"


#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <climits>
#include <algorithm>
#include <functional>


namespace DraftsmanCore {
namespace __private__ {


namespace __detail__ {


//--------------------------------------------------------------------------------------
//----------------------------------------------------- Private Unit Forward Declaration


unsigned char random_char();
std::string generate_hex( const  unsigned  int  len );


//--------------------------------------------------------------------------------------
//---------------------------------------------------------- Private Unit Implementation


unsigned char random_char() {
    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dis( 0, 255 );
    return  static_cast< unsigned  char >( dis( gen ) );
}

std::string generate_hex( const  unsigned  int  len ) {
    std::stringstream ss;
    for( unsigned  int i = 0; i < len; i++) {
        auto rc = random_char();
        std::stringstream hexstream;
        hexstream << std::hex << int( rc );
        auto hex = hexstream.str(); 
        ss << ( hex.length() < 2 ? '0' + hex : hex );
    }
    return  ss.str();
}


} // namespace __detail__


//--------------------------------------------------------------------------------------
//---------------------------------------------------------------- Public Implementation


std::string generate_uuid( const unsigned int len )
{
    return  ::DraftsmanCore::__private__::__detail__::generate_hex( len );
}


} // namespace __private__
} // namespace DraftsmanCore
