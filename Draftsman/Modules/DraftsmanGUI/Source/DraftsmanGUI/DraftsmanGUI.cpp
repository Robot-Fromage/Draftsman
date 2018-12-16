#include "DraftsmanGUI/DraftsmanGUI.hpp"
#include "DraftsmanCore/DraftsmanCore.hpp"

#ifdef DRAFTSMANGUI

namespace  DraftsmanGUI {

const char* test()
{
    auto t = ::DraftsmanCore::test();
    return  "DraftsmanGUI";
}

} // namespace  DraftsmanGUI

#endif // DRAFTSMANGUI
