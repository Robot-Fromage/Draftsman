#include "Test_DraftsmanGUI.hpp"
#include "DraftsmanCore/DraftsmanCore.hpp"
#include "DraftsmanGUI/DraftsmanGUI.hpp"

#ifdef TEST_DRAFTSMANGUI

int main()
{
    while(true)
    {
        ::DraftsmanCore::test();
        ::DraftsmanGUI::test();
    }

    return  0;
}

#endif // TEST_DRAFTSMANGUI
