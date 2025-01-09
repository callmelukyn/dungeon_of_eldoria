#ifndef MAGE_BUILDER_H
#define MAGE_BUILDER_H
#include "player_builder.h"


class MageBuilder final : public PlayerBuilder {
public:
    MageBuilder();

    ~MageBuilder() override;

    void createPlayer() override;
};


#endif //MAGE_BUILDER_H
