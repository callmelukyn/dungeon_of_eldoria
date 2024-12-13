#ifndef WARRIORBUILDER_H
#define WARRIORBUILDER_H
#include "playerBuilder.h"


class WarriorBuilder final : public PlayerBuilder {
public:
    WarriorBuilder();

    ~WarriorBuilder() override;

    void createPlayer() override;
};


#endif //WARRIORBUILDER_H
