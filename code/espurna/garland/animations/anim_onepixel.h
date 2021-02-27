#if GARLAND_SUPPORT

#include "../anim.h"
#include "../color.h"
#include "../palette.h"

//------------------------------------------------------------------------------
class AnimOnePixel : public Anim {
   public:
    AnimOnePixel() : Anim("OnePixel") {
    }

    void SetupImpl() override {
        for (int i = 0; i < numLeds; ++i) {
			leds[i] = Color(0,0,0);
		}
		pos = 0;
    }

    void Run() override {
		curColor = palette->getRndInterpColor();
		
        for (int i = 0; i < numLeds; ++i) {
			if (i == pos) {
				leds[i] = curColor;
			}
			else {
				leds[i] = Color(0,0,0);
			}
		}
		pos++;
		
		if (pos == numLeds) {
				pos = 0;
		}
	}
};

#endif  // GARLAND_SUPPORT
