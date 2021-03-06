#include "pixie-rect.hpp"

using namespace Pixie;

Rect::Rect(Coord tl, Coord br) : tl(tl), br(br) { }

Rect::Rect(CoordF tl, CoordF br) : tl(Coord(tl)), br(Coord(br)) { }

Rect::Rect(int x, int y, int width, int height) :
    tl(Coord(x, y)),
    br(Coord(x + width, y + height))
{

}

Rect::Rect(float x, float y, float width, float height) :
    tl(CoordF(x, y)),
    br(CoordF(x, y) + CoordF(width, height))
{

}

int Rect::x() const
{
    return tl.x;
}

int Rect::y() const
{
    return tl.y;
}

int Rect::width() const
{
    return br.x - tl.x;
}

int Rect::height() const
{
    return br.y - tl.y;
}

int &Rect::top()
{
    return tl.y;
}

int &Rect::left()
{
    return tl.x;
}

int &Rect::right()
{
    return br.x;
}

int &Rect::bottom()
{
    return br.y;
}

int Rect::area() const
{
    return width() * height();
}

int Rect::perimeter() const
{
    return 2 * (width() + height());
}

bool Rect::contains(Coord c) const
{
    return (c.x > tl.x && c.x < br.x &&
            c.y > tl.y && c.y < br.y);
}

bool Rect::contains(Rect r) const
{
    return (contains(r.tl) && contains(r.br));
}

Rect Rect::transform(Transform t) const
{
    return Rect( tl.transform(t), br.transform(t) );
}

Rect Rect::operator+(const Coord &c) const
{
    return Rect( tl + c, br + c );
}

Rect Rect::operator-(const Coord &c) const
{
    return Rect( tl - c, br - c);
}
