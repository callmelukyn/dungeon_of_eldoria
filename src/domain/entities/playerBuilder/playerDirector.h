#ifndef PLAYERDIRECTOR_H
#define PLAYERDIRECTOR_H
#include "playerBuilder.h"


class PlayerDirector {
    PlayerBuilder *m_builder;

public:
    explicit PlayerDirector(PlayerBuilder *builder);

    void setBuilder(PlayerBuilder *builder);

    Player *createPlayer() const;
};


#endif //PLAYERDIRECTOR_H
