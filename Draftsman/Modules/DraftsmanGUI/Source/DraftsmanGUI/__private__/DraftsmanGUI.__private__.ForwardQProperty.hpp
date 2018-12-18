/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.ForwardQProperty.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Definition and Implementation of DraftsmanGUI ForwardQProperty private preprocessor module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once

//TODO: REMOVE OBSOLETE

#define FORWARD_QPROPERTY( iType, iName )                        \
    iType m##iName;                                                     \
    public: const  iType##& get##iName() { return m##iName; }           \
    public: void set##iName( const  iType##& iIn ) { m##iName = iIn; }  \
    private:
