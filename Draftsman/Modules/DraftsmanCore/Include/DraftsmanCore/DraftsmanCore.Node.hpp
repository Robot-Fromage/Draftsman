/***************************************************************************************
 *
 *   DraftsmanCore
 *__________________
 *
 * @file DraftsmanCore.Node.h
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Definition of DraftsmanCore Node class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <string>


namespace DraftsmanCore {


class Node
{
    typedef  Node  tSelf;

public:
    // Construction / Destruction
    ~Node();
    Node();

public:
    // Getters / Setters
    const  std::string&  GetName();
    const  std::string&  GetUUID();

private:
    // Private Data Members
    std::string  mName;
    std::string  mUUID;

};


} // namespace DraftsmanCore
