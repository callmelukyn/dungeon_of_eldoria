#include "mummy.h"

Mummy::Mummy(const Position mummyPosition)
    : Enemy(EnemyType::mummy, 10, 10, 300, 30, 10, 2, mummyPosition) {
}
