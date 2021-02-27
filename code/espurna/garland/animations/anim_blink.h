#if GARLAND_SUPPORT

#include "../anim.h"
#include "../color.h"
#include "../palette.h"

//------------------------------------------------------------------------------
class AnimBlink : public Anim {
   public:
    AnimBlink() : Anim("Blink") {
    }

    void SetupImpl() override {
        curColor = palette->getRndInterpColor();

        for (int i = 0; i < numLeds; ++i) {
			leds[i] = curColor;
		}

		phase = 0;
    }


    void Run() override {
		curColor = palette->getRndInterpColor();
		
        for (int i = 0; i < numLeds; ++i) {
			if (phase % 2) {
				leds[i] = curColor;
			}
			else {
				leds[i] = Color(0,0,0);
			}
		}

		phase++;
	}
};

#endif  // GARLAND_SUPPORT
