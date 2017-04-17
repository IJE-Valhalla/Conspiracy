#include "scene.hpp"

using namespace engine;

Scene::Scene(std::string newName){
  name = newName;
}

Scene::~Scene(){

}

void Scene::addSprite(Sprite & newSprite){
  sprite = &newSprite;
}

void Scene::init(){
  sprite->init();
}

void Scene::draw(){
  //sprite->draw(0,0);
}

void Scene::shutdown(){
  sprite->shutdown();
}
