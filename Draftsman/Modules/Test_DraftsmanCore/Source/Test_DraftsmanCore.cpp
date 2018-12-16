#include "Test_DraftsmanCore.hpp"

#include "DraftsmanCore/DraftsmanCore.hpp"

#include "tinyxml2.h"

#ifdef TEST_DRAFTSMANCORE

int main()
{
    ::tinyxml2::XMLDocument xmlDoc;
    ::tinyxml2::XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);
    ::tinyxml2::XMLElement * pElement = xmlDoc.NewElement("IntValue");
    pElement->SetText(10);
    pRoot->InsertEndChild(pElement);

    while(true)
    {
        ::DraftsmanCore::test();
    }

    return  0;
}

#endif // TEST_DRAFTSMANCORE
