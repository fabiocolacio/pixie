#ifndef __PIXIE_SPRITE_HPP__
#define __PIXIE_SPRITE_HPP__

#include <string>
#include <vector>

#include "pixie-rgba.hpp"
#include "pixie-coord.hpp"
#include "pixie-layer.hpp"

namespace Pixie {

class Sprite {
public:
    Sprite(const std::string &filename);
    Sprite(int width, int height, bool has_alpha, RGBA bg_color);

    Coord size() const;
    int width() const;
    int height() const;
    bool get_has_alpha() const;
    RGBA get_bg_color() const;

    std::size_t n_layers() const;
    std::vector<Layer> &get_layers();
    const std::vector<Layer> &get_layers() const;
    Layer &operator[](std::size_t idx);
    const Layer &operator[](std::size_t idx) const;

private:
    std::vector<Layer> layers;

    bool has_alpha = true;
    RGBA bg_color = RGBA(0xffffff00);
};

}

#endif
