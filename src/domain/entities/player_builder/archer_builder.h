#ifndef ARCHER_BUILDER_H
#define ARCHER_BUILDER_H
#include "player_builder.h"


class ArcherBuilder final : public PlayerBuilder {
public:
    ArcherBuilder();

    ~ArcherBuilder() override;

    void createPlayer() override;
};


#endif //ARCHER_BUILDER_H
