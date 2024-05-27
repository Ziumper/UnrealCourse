#pragma once

class Player 
{
    public:
        Player(): m_index(-1) {};
        Player(int index): m_index(index) {};
        virtual void Move();
    protected:
        int m_index;
};
