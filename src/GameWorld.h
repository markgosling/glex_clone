#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>

#include <GL/gl.h>

#include "common.h"
#include "GameAssetManager.h"
#include "CubeAsset.h"
#include "PyramidAsset.h"
#include "GameAsset.h"

/**
 * GameWorld allows us to separate the management of the game world from the
 * nuts and bolts of game loop initialisation.  The GameWorld currently has
 * a very simplified scene graph consisiting of a single GameAssetManager.
 */
class GameWorld {
 public:
  /**
   * We thread the ApplicationMode through the GameWorld ss we want to read it
   * in from the user.  Threading the state through the various function calls
   * is preferable (in this case) to having some kind of global state.
   */
  GameWorld(ApplicationMode);

  /**
   * Calling Draw() will draw the entire world.
   */
  void Draw();

  //Method which passes player directional inputs from the player from main.cc
  //to GameAssetManager so the camera position can be updated.
  void UpdateCameraPosition(InputDirection, int mouse_x, int mouse_y);


 private:
  std::shared_ptr<GameAssetManager> asset_manager;

};
#endif // GAMEWORLD_H
