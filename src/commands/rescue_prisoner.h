#ifndef RESCUE_PRISONER_H
#define RESCUE_PRISONER_H
#include "../domain/value_objects/prisoner.h"

class RescuePrisoner {
public:
    RescuePrisoner(Prisoner *prisoner, Player *player, const std::vector<Map *> &maps, int currentLevel);
};

#endif //RESCUE_PRISONER_H
