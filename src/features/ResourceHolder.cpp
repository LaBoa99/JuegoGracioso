#include "TextureHolder.hpp"
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std:: string& filename){

    std::unique_ptr<Resource> resource (new Resource());
    if(!resource->loadFromFile(filename)){
        throw std::runtime_error("ResourceHolder::load - failed to load " + filename);
    }

    auto insertet = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
};

// Este metodo solo sirve para los shaders ya que estos ocupan un parametro mas en load from file...
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std:: string& filename, const Parameter secondParam){

    std::unique_ptr<Resource> resource (new Resource());
    if(!resource->loadFromFile(filename, secondParam)){
        throw std::runtime_error("ResourceHolder::load - failed to load " + filename);
    }

    auto insertet = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
};

Resource& ResourceHolder<Resource, Identifier>::get(Textures::ID id){
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}
