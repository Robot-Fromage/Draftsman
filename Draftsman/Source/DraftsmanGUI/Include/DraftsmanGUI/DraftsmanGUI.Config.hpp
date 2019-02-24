/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.Config.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Definition of DraftsmanGUI Config module
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <string>


#define     DRAFSTMAN_GUI_VERSION_NUMBER    0


// Enabled:     Smooth  perf in View,   Low     perf on Resize
// Disabled:    Low     perf in View,   Smooth  perf on Resize
#define     DRAFTSMANGUI_GRAPH_WITH_QOPENGLWIDGET


namespace DraftsmanGUI {
namespace Config {


const  int              gui_version_number();
const  int              core_version_number();
const  bool             with_opengl_context();
const  std::string&     GetResourcePath();
const  std::string&     GetStyleDirRelativePath();
const  std::string&     GetStyleFileName();
std::string             GetStyleFilePath();
void                    SetResourcePath(            const  std::string&  iStr );
void                    SetStyleDirRelativePath(    const  std::string&  iStr );
void                    SetStyleFileName(           const  std::string&  iStr );


} // namespace Config
} // namespace DraftsmanGUI
