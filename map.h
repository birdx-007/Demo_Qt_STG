#ifndef MAP_H
#define MAP_H

#include<QPixmap>
namespace stg
{
    class Map
    {
    public:
        Map();
        void updateMapPosition();
        QPixmap m_map1;
        QPixmap m_map2;
        int m_map1_posY;
        int m_map2_posY;
        int m_scroll_speed;
    };
}
#endif // MAP_H
