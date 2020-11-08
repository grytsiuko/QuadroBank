#ifndef UI_OBJECT_H
#define UI_OBJECT_H

#include <QWidget>

template <typename A, class B>
class object_ui
{
public:
    A* getUi(B& b){
        return b.ui;
    };
    object_ui(){};
};

#endif // UI_OBJECT_H
