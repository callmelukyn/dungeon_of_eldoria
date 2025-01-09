//
// Created by Lukyn on 23.12.2024.
//

#include "basilisk.h"

Basilisk::Basilisk(const Position basiliskPosition)
    : Enemy(EnemyType::basilisk, 50, 45, 500, 80, 40, 5, basiliskPosition) {
}
