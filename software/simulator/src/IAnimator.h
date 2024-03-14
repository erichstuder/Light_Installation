#pragma once

class IAnimator {
    public:
        virtual void animate(const char* fileName) = 0;
};
