#ifndef WARRIOR_BUILDER_H
#define WARRIOR_BUILDER_H
#include "player_builder.h"


class WarriorBuilder final : public PlayerBuilder {
public:
    WarriorBuilder();

    ~WarriorBuilder() override;

    void createPlayer() override;
};


#endif //WARRIOR_BUILDER_H
