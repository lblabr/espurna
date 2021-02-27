#if GARLAND_SUPPORT

#include "../anim.h"
#include "../color.h"
#include "../palette.h"

//------------------------------------------------------------------------------
class AnimFillReverse : public Anim {
   public:
    AnimFillReverse() : Anim("FillReverse") {
    }

    void SetupImpl() override {
        for (int i = 0; i < numLeds; ++i) {
			leds[i] = Color(0,0,0);
		}

		inc = 0;
		pos = 0;
    }

    void Run() override {
		curColor = palette->getRndInterpColor();

		for (int i = 0; i < numLeds - inc; ++i) {
			if (i == pos) {
				leds[pos] = curColor;
			}
			else {
				leds[i] = Color(0,0,0);
			}
		}

		pos++;

		if (pos >= numLeds - inc) {
			pos = 0;
			
			if (inc >= numLeds) { 
				SetupImpl();			
			}
			else {
				inc++;
			}
		}

	}
};

#endif  // GARLAND_SUPPORT
