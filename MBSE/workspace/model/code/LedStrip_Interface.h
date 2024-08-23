#pragma once



class LedStrip_Interface {
    public:
        virtual ~LedStrip_Interface() {}
        virtual void setPixelColor(EByte z, EByte r, EByte g, EByte b) = 0;
        virtual void animate() = 0;
};
