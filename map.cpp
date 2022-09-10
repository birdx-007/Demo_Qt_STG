#include "map.h"
namespace stg
{
    Map::Map()
    {
        m_map1.load(":/res/background.png");
        m_map2.load(":/res/background.png");
        m_map1_posY=-1063;
        m_map2_posY=0;
        m_scroll_speed=1;
    }

    void Map::updateMapPosition()
    {
        m_map1_posY+=m_scroll_speed;
        if(m_map1_posY>=0)
        {
            m_map1_posY=-1063;
        }
        m_map2_posY+=m_scroll_speed;
        if(m_map2_posY>=1063)
        {
            m_map2_posY=0;
        }
    }
}
