/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.__private__.ForwardQProperty.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once

#define FORWARD_QPROPERTY( iType, iName )                        \
    iType m##iName;                                                     \
    public: const  iType##& get##iName() { return m##iName; }           \
    public: void set##iName( const  iType##& iIn ) { m##iName = iIn; }  \
    private:
