#include <string>
using std::to_string;

#include "bnMobHealthUI.h"
#include "bnEntity.h"
#include "bnTextureResourceManager.h"

#include "bnLogger.h"

MobHealthUI::MobHealthUI(void)
  : mob(nullptr),
  font(nullptr) {
}

MobHealthUI::MobHealthUI(Entity* _mob)
  : mob(_mob) {
  font = TextureResourceManager::GetInstance().LoadFontFromFile("resources/fonts/mgm_nbr_pheelbert.ttf");
  setFont(*font);
  setScale(0.8f, 0.8f);
}

MobHealthUI::~MobHealthUI(void) {
  delete font;
}

void MobHealthUI::Update() {
  if (mob) {
    setOrigin(getLocalBounds().width, 0);
    setString(to_string(mob->GetHealth()));

    int* res = mob->getAnimOffset();

    if (res != nullptr) {
      //std::cout << "res: { " << res[0] << ", " << res[1] << " } " << std::endl;
      setPosition(mob->getPosition().x + res[0], mob->getPosition().y + res[1]);
      delete[] res;
    } else {
      //std::cout << "nullptr!" << std::endl;
      setPosition(mob->getPosition().x, mob->getPosition().y);
    }
  }
}