#include "Test_DraftsmanGUI.hpp"

#include "DraftsmanCore/DraftsmanCore.hpp"
#include "DraftsmanGUI/DraftsmanGUI.hpp"

#include "tinyxml2.h"

#include <QApplication>
#include <QWidget>

#ifdef TEST_DRAFTSMANGUI

int main( int argc, char *argv[] )
{
    ::DraftsmanCore::test();
    ::DraftsmanGUI::test();

    ::tinyxml2::XMLDocument xmlDoc;
    ::tinyxml2::XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);
    ::tinyxml2::XMLElement * pElement = xmlDoc.NewElement("IntValue");
    pElement->SetText(10);
    pRoot->InsertEndChild(pElement);

    QApplication app( argc, argv );
    QWidget w;
    w.show();

    int exit_code = app.exec();

    return  exit_code;
}

#endif // TEST_DRAFTSMANGUI
