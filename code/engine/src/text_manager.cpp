#include "text_manager.hpp"

using namespace engine;

TextManager TextManager::instance;

TTF_Font* TextManager::loadFont(std::string path, int size){

    std::pair <std::string, int> search (path.c_str(), size);
    auto find = listFont.find(search);

    if (find == listFont.end()){
       TTF_Font * font = TTF_OpenFont(path.c_str(), size);
       if(font == NULL){
         ERROR("Font invalid!");
         exit(-1);
       }
        listFont[search] = font;
    }

    return listFont[search];
}

void TextManager::unload(){
  WARN("Dealocate fonts.");
  for(auto font: listFont){
         TTF_CloseFont(font.second);
  }

  listFont.clear();
}
