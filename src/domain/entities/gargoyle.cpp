//
// Created by Lukyn on 27.12.2024.
//

#include "gargoyle.h"

Gargoyle::Gargoyle(const Position gargoylePosition): Enemy(EnemyType::gargoyle, 50, 35, 400, 65,
                                                           30, 4, gargoylePosition) {
}
