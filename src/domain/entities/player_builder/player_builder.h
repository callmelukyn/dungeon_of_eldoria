#ifndef PLAYER_BUILDER_H
#define PLAYER_BUILDER_H

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


#endif //PLAYER_BUILDER_H
