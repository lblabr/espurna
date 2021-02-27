#if GARLAND_SUPPORT

#include "../anim.h"
#include "../color.h"
#include "../palette.h"

//------------------------------------------------------------------------------
class AnimFill : public Anim {
   public:
    AnimFill() : Anim("Fill") {
    }

    void SetupImpl() override {
        for (int i = 0; i < numLeds; ++i) {
			leds[i] = Color(0,0,0);
		}
		pos = 0;
    }

    void Run() override {
		curColor = palette->getRndInterpColor();

		leds[pos] = curColor;

		if (pos == numLeds) {
			SetupImpl();
		}
		else {
			pos++;
		}
	}
};

#endif  // GARLAND_SUPPORT
