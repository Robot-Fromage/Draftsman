/***************************************************************************************
 *
 *   Test_DraftsmanGUI
 *__________________
 *
 * @file Test_DraftsmanGUI.cpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 16/12/2018
 * @brief Implementation of DraftsmanGUI Test Executable
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#include "Test_DraftsmanGUI.hpp"


#include "tinyxml2.h"


#include <QApplication>
#include <QWidget>


#include <DGGraph>


#ifdef TEST_DRAFTSMANGUI

int main( int argc, char *argv[] )
{
    ::tinyxml2::XMLDocument xmlDoc;
    ::tinyxml2::XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);
    ::tinyxml2::XMLElement * pElement = xmlDoc.NewElement("IntValue");
    pElement->SetText(10);
    pRoot->InsertEndChild(pElement);

    QApplication app( argc, argv );
    ::DG::Graph w;
    w.show();

    int exit_code = app.exec();

    return  exit_code;
}

#endif // TEST_DRAFTSMANGUI
