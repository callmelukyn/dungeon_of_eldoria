#ifndef ARCHERBUILDER_H
#define ARCHERBUILDER_H
#include "playerBuilder.h"


class ArcherBuilder final : public PlayerBuilder {
public:
    ArcherBuilder();

    ~ArcherBuilder() override;

    void createPlayer() override;
};


#endif //ARCHERBUILDER_H
