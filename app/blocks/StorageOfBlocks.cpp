#pragma once

#include "Block.h"

class I_Block : public Block
    {
    public:
        I_Block() : Block()
            {
                id = 3;
                cells = {
                            {0, {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)}},
                            {1, {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)}},
                            {2, {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)}},
                            {3, {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)}}
                        };
                move(0, 3);
            }
    };

class J_Block : public Block
    {
    public:
        J_Block() : Block()
            {
                id = 2;
                cells = {
                            {0, {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)}},
                            {1, {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)}},
                            {2, {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)}},
                            {3, {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)}}
                        };
                move(0, 3);
            }
    };

class L_Block : public Block
    {
    public:
        L_Block() : Block()
            {
                id = 1;
                cells = {
                            {0, {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)}},
                            {1, {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)}},
                            {2, {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)}},
                            {3, {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}}
                        };
                move(0, 3);
            }
    };

class O_Block : public Block
    {
    public:
        O_Block() : Block()
            {
                id = 4;
                cells = {
                            {0, {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)}}
                        };
                move(0, 3);
            }
    };

class S_Block : public Block
    {
    public:
        S_Block() : Block()
            {
                id = 5;
                cells = {
                            {0, {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)}},
                            {1, {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)}},
                            {2, {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)}},
                            {3, {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)}}
                        };
                move(0, 3);
            }
    };

class T_Block : public Block
    {
    public:
        T_Block() : Block()
            {
                id = 6;
                cells = {
                            {0, {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)}},
                            {1, {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)}},
                            {2, {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)}},
                            {3, {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)}}
                        };
                move(0, 3);
            }
    };

class Z_Block : public Block
    {
    public:
        Z_Block() : Block()
            {
                id = 7;
                cells = {
                            {0, {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)}},
                            {1, {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)}},
                            {2, {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)}},
                            {3, {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)}}
                        };
                move(0, 3);
            }
    };
