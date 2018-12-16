/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.Node.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanCore Node class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "DraftsmanCore/DraftsmanCore.Node.hpp"


#include "DraftsmanCore.__private__.GenerateUUID.hpp"


#define  DEFAULT_NODE_NAME      "<Untitled_Node>"
#define  DEFAULT_NODE_UUID_LEN  16


namespace DraftsmanCore {


//--------------------------------------------------------------------------------------
//----------------------------------------------------------- Construction / Destruction


Node::~Node()
{
}


Node::Node() :
    mName( DEFAULT_NODE_NAME ),
    mUUID( ::DraftsmanCore::__private__::generate_uuid( DEFAULT_NODE_UUID_LEN ) )
{
}


//--------------------------------------------------------------------------------------
//-------------------------------------------------------------------- Getters / Setters


const  std::string&
Node::GetName()
{
    return  mName;
}


const  std::string&
Node::GetUUID()
{
    return  mUUID;
}


} // namespace DraftsmanCore
