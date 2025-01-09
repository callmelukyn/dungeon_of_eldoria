#ifndef PLAYER_DIRECTOR_H
#define PLAYER_DIRECTOR_H
#include "player_builder.h"


class PlayerDirector {
    PlayerBuilder *m_builder;

public:
    explicit PlayerDirector(PlayerBuilder *builder);

    void setBuilder(PlayerBuilder *builder);

    Player *createPlayer() const;
};


#endif //PLAYERDIRECTOR_H
