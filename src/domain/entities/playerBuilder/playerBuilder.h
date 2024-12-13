#ifndef PLAYERBUILDER_H
#define PLAYERBUILDER_H

#include "../player.h"


class PlayerBuilder {
protected:
    Player *m_player;

public:
    PlayerBuilder();

    virtual ~PlayerBuilder() = default;

    virtual void createPlayer() = 0;

    Player *getPlayer() const;
};


#endif //PLAYERBUILDER_H
