#pragma once

#include "IAnimator.h"

class Animator: public IAnimator {
    public:
        void animate(const char* fileName);
};
