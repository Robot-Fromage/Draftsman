/*************************************************************************
*
*   Draftsman
*__________________
*
* Draftsman.GUI.Config.h
*
* Clement Berthaud
* Please refer to LICENSE.TXT
*/

#pragma once


#include <string>


#define     DRAFSTMAN_GUI_VERSION_NUMBER  0

// Enabled:     Smooth  perf in View,   Low     perf on Resize
// Disabled:    Low     perf in View,   Smooth  perf on Resize
#define     DRAFTSMAN_GUI_GRAPH_WITH_QOPENGLWIDGET

// Enabled: Very low perf // DO NOT USE !
//#define     DRAFTSMAN_GUI_NODE_WITH_QGRAPHICSDROPSHADOWEFFECT


namespace  Draftsman {
namespace  GUI {
namespace  Config {


// Public Define Config
const  int  gui_version_number();
const  int  core_version_number();
const  bool with_opengl_context();

// Private Tampon Config
// Get
const  std::string&     GetResourcePath();
const  std::string&     GetStyleDirRelativePath();
const  std::string&     GetStyleFileName();
std::string             GetStyleFilePath();

// Set
void  SetResourcePath(          const  std::string&  iStr );
void  SetStyleDirRelativePath(  const  std::string&  iStr );
void  SetStyleFileName(         const  std::string&  iStr );


} // namespace  Config
} // namespace  GUI
} // namespace  Draftsman

