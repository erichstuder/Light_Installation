#pragma once

#include "Animator_Interface.h"

class Animator: public Animator_Interface {
    public:
        void animate(const char* fileName);
};
