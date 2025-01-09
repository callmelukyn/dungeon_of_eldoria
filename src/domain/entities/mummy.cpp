#include "mummy.h"

Mummy::Mummy(const Position mummyPosition)
    : Enemy(EnemyType::mummy, 10, 10, 100, 20, 10, 2, mummyPosition) {
}
