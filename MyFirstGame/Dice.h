#pragma once
#include "Quad.h"
class Dice :
    public Quad
{
public:
    Dice();
    ~Dice();
    HRESULT Initialize();
    void Draw();
    void Release();
};

