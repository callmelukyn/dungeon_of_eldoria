//
// Created by Lukyn on 23.12.2024.
//

#ifndef ADD_PRISONER_H
#define ADD_PRISONER_H
#include <vector>
#include "../domain/entities/prisoner.h"
#include "../map/map.h"

class AddPrisoner {
    Prisoner *m_prisoner;
    std::vector<Map *> m_maps;

public:
    explicit AddPrisoner(const std::vector<Map *> &maps);

    ~AddPrisoner();

    void addPrisoner(int currentLevel, Position position);

    Prisoner *getPrisoner() const;
};


#endif //ADD_PRISONER_H
