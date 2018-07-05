#ifndef __PIXIE_SPRITE_HPP__
#define __PIXIE_SPRITE_HPP__

#include <string>
#include <vector>

#include "pixie-coord.hpp"
#include "pixie-layer.hpp"

namespace Pixie {

class Sprite {
public:
    Sprite(const std::string &filename);

    Coord size() const;
    int width() const;
    int height() const;

    std::size_t n_layers() const;
    std::vector<Layer> &get_layers();
    const std::vector<Layer> &get_layers() const;
    Layer &operator[](std::size_t idx);
    const Layer &operator[](std::size_t idx) const;

private:
    std::vector<Layer> layers;
};

}

#endif