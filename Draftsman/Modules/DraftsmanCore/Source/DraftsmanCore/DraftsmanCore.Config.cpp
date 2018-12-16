/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.Config.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanCore Config module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanCore/DraftsmanCore.Config.hpp"


#include "DraftsmanCore.__private__.Config.hpp"
#include "DraftsmanCore.__private__.GenerateUUID.hpp"


namespace  DraftsmanCore {
namespace  Config {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------------------- Implementation


const  int
version_number()
{
    return  DRAFSTMAN_CORE_VERSION_NUMBER;
}


std::string
test_uuid( const unsigned int len )
{
    return  ::DraftsmanCore::__private__::generate_uuid( len );
}


// Get
const  std::string&
GetResourcePath()
{
    return  ::DraftsmanCore::__private__::Config::Get()->GetResourcePath();
}


// Set
void
SetResourcePath( const  std::string&  iStr )
{
    ::DraftsmanCore::__private__::Config::Get()->SetResourcePath( iStr );
}


} // namespace  Config
} // namespace  DraftsmanCore
