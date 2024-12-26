//
// Created by Lukyn on 27.12.2024.
//

#include "ghoul.h"

Ghoul::Ghoul(Position ghoulPosition): Enemy(EnemyType::ghoul, 35, 30, 300, 55, 25, 3, 1, ghoulPosition) {
}
