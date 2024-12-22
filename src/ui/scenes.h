//
// Created by Lukyn on 06.12.2024.
//

#ifndef SCENES_H
#define SCENES_H

class Scenes {
    int m_currentScene;

public:
    Scenes();

    void printScenes() const;

    void setCurrentScene(int currentScene);

    void incrementCurrentScene(char keyboardKey);

    int getCurrentScene() const;

    //Scene text
    void continueHint() const;

    void prologText1() const;

    void prologText2() const;

    void prologText3() const;

    void prologText4() const;

    //Scene arts
    void prologArt1() const;

    void prologArt2() const;

    void prologArt3() const;

    void prologArt4() const;

    //Whole cutscenes
    void sceneProlog1() const;

    void sceneProlog2() const;

    void sceneProlog3() const;

    void sceneProlog4() const;

    //Menu scenes
    void sceneHeaderMenu() const;

    void sceneSmallHeaderMenu() const;

    void sceneMainSelectedPlay() const;

    void sceneMainSelectedCredits() const;

    void sceneMainSelectedHTP() const;

    void sceneMainSelectedExit() const;

    void sceneCreditsMenu() const;

    void sceneHTPMenu() const;

    void sceneRoleSelectedWarrior() const;

    void sceneRoleSelectedArcher() const;

    void sceneRoleSelectedMage() const;

    //Shop scenes
    void sceneShopHeader() const;

    void sceneShopMainSelectedWeapons() const;

    void sceneShopMainSelectedArmor() const;

    void sceneShopMainSelectedPotions() const;

    void sceneShopMainSelectedExit() const;

    void sceneShopWeaponsSelectedWeapon1() const;

    void sceneShopWeaponsSelectedWeapon2() const;

    void sceneShopWeaponsSelectedWeapon3() const;

    void sceneShopArmorSelectedArmor1() const;

    void sceneShopArmorSelectedArmor2() const;

    void sceneShopArmorSelectedArmor3() const;

    void sceneShopPotionsSelectedPotion1() const;

    void sceneShopPotionsSelectedPotion2() const;
};


#endif //SCENES_H
