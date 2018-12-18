/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.Config.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Definition of DraftsmanCore Config module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <DCTypes>


#include <string>


#define DRAFSTMAN_CORE_VERSION_NUMBER  0


namespace DraftsmanCore {
namespace Config {


const  int              version_number();
std::string             test_uuid( const unsigned int len );
const  std::string&     GetResourcePath();
void                    SetResourcePath( const  std::string&  iStr );


} // namespace Config
} // namespace DraftsmanCore
