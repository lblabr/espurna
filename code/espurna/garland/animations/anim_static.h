#if GARLAND_SUPPORT

#include "../anim.h"
#include "../palette.h"

//------------------------------------------------------------------------------
class AnimStatic : public Anim {
   public:
    AnimStatic() : Anim("Static") {
    }

    void SetupImpl() override {
        curColor = palette->getRndInterpColor();

        for (int i = 0; i < numLeds; ++i) {
			leds[i] = curColor;
		}
    }

    void Run() override {
    }
};

#endif  // GARLAND_SUPPORT
