#ifndef INTERACTION_H
#define INTERACTION_H
#include "../domain/entities/player.h"

class Interaction {
public:
    virtual ~Interaction() = default;

    virtual void interaction(Player *player) = 0;
};

#endif //INTERACTION_H
