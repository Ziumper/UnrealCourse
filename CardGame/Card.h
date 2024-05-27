#pragma once


enum class Color : char
{
    Pik,
    Trefl,
    Karo,
    Kier,

    SIZE
};

enum class Rank : char
{
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _10,
    _J,
    _D,
    _K,
    _AS,

    SIZE
};

struct Card
{
    Color color;
    Rank rank;
};
