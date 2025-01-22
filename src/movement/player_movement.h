#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H
#include <functional>

#include "../domain/entities/enemy.h"
#include "../domain/entities/player.h"

class PlayerMovement {
    Player *m_player;

    bool isBlockedByEnemy(const std::vector<Enemy *> &enemies) const;

    Position calculateNextPosition(char keyboardKey) const;

    void handleMovement(Map *map, char nextTile, Position nextPosition,
                        const std::function<void()> &nextLevel) const;

    void moveToPosition(Map *map, Position nextPosition) const;

    void advanceToNextLevel(Map *map, const std::function<void()> &nextLevel) const;

public:
    explicit PlayerMovement(Player *player);

    void movePlayer(char keyboardKey, const std::vector<Map *> &maps,
                    int currentLevel, const std::function<void()> &nextLevel,
                    const std::vector<Enemy *> &enemies) const;
};

#endif //PLAYER_MOVEMENT_H
