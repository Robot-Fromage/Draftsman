#include "Test_DraftsmanGUI.hpp"
#include "DraftsmanCore/DraftsmanCore.hpp"
#include "DraftsmanGUI/DraftsmanGUI.hpp"

#include <QApplication>
#include <QWidget>

#ifdef TEST_DRAFTSMANGUI

int main( int argc, char *argv[] )
{
    ::DraftsmanCore::test();
    ::DraftsmanGUI::test();

    QApplication app( argc, argv );
    QWidget w;
    w.show();

    int exit_code = app.exec();

    return  exit_code;
}

#endif // TEST_DRAFTSMANGUI
