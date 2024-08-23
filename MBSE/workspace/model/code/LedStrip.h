#pragma once



class LedStrip {
    public:
        ~LedStrip() {}
        void LedStrip(EByte pin, AnimationCallback_t animationCallback, EInt numberOfLeds);
        void setPixelColor(EByte z, EByte r, EByte g, EByte b);
        void animate();
};
