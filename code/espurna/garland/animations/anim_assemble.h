#if GARLAND_SUPPORT

#include <list>

#include "../anim.h"
#include "../color.h"
#include "../palette.h"

//------------------------------------------------------------------------------
class AnimAssemble : public Anim {
   public:
    AnimAssemble() : Anim("Assemble") {
    }
    void SetupImpl() override {
        inc = 1 + (rngb() >> 5);
        if (secureRandom(10) > 5) {
            inc = -inc;
        }

        int p = 0;
        for (int i = 0; i < numLeds; i++) {
            Color c = palette->getCachedPalColor((byte)p);
            leds[i] = c;

            p = p + inc;
            if (p >= 256) {
                p = p - 256;
            } else if (p < 0) {
                p = p + 256;
            }
        }
    }

    void Run() override {
    }
};

// struct Dot {
//     float point = secureRandom(0, numLeds/2);
//     int len = secureRandom(10, 20);
//     float speed = ((float)secureRandom(4, 10)) / 10;
//     Color color;
//     int dir = 1;
//     Dot(Palette* pal) : color(pal->getRndInterpColor()) {
//         // DEBUG_MSG_P(PSTR("[GARLAND] Dot created head = %d len = %d speed = %g cr = %d cg = %d cb = %d\n"), head, len, speed, color.r, color.g, color.b);
//         if (secureRandom(10) > 5) {
//             head = numLeds-head;
//             dir = -1;
//         }
//     }
// };

#endif  // GARLAND_SUPPORT