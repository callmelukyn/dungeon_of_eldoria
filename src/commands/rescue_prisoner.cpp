#include "rescue_prisoner.h"

RescuePrisoner::RescuePrisoner(Prisoner *prisoner, Player *player, const std::vector<Map *> &maps, int currentLevel) {\
    player->addXp(30);
    player->addCoins(200);
    maps[currentLevel]->clearCharacterFromPosition(prisoner->getPosition());
    prisoner->setPosition(Position{9999, 9999});
}
