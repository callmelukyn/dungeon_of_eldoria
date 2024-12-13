#ifndef MAGEBUILDER_H
#define MAGEBUILDER_H
#include "playerBuilder.h"


class MageBuilder final : public PlayerBuilder {
public:
    MageBuilder();

    ~MageBuilder() override;

    void createPlayer() override;
};


#endif //MAGEBUILDER_H
