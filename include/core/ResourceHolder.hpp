#ifndef TEXTUREHOLDER_HPP
#define TEXTUREHOLDER_HPP


template <typename Resource, typename Identifier>
class ResourceHolder
{

public:
    void load(Identifier id, const std::string& filename);
    const Resource& get(Identifier id,) const;
    Resource& get(Identifier id, id);

private:
    std::map<Identifier, std::unique_ptr<Resource> mResourceMap;

};

#endif // TEXTUREHOLDER_HPP
