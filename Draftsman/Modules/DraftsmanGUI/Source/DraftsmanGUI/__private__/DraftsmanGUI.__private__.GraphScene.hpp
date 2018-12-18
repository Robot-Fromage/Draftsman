/***************************************************************************************
 *
 *   DraftsmanGUI
 *__________________
 *
 * @file DraftsmanGUI.__private__.GraphScene.hpp
 * @author Clement BERTHAUD <code@clementberthaud.com>
 * @date 18/12/2018
 * @brief Definition of DraftsmanGUI GraphScene private class
 * @licence MIT License - Copyright (c) 2018-2019 Draftsman - Clement BERTHAUD <code@clementberthaud.com>
 */

#pragma once


#include <QGraphicsScene>


#include "__private__/DraftsmanGUI.__private__.ForwardQProperty.hpp"


namespace DraftsmanGUI {
namespace __private__ {


class GraphScene : public QGraphicsScene
{
    Q_OBJECT

    typedef  QGraphicsScene tSuperClass;
    typedef  GraphScene     tSelf;

public:
    // Construction / Destruction
    virtual  ~GraphScene();
    GraphScene( QObject* iParent = NULL );

};


} // namespace __private__
} // namespace DraftsmanGUI
