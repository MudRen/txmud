//bank_d.c 钱庄下的迷宫。
inherit VRM_SERVER;
void create()
{
        set_inherit_room(ROOM);
        {if (random(7)>3)
        set_maze_npcs(__DIR__"npc/killer");
        }
        set_maze_long(8);
        set_entry_dir("east");
        set_link_entry_dir("east");
        set_link_entry_room(__DIR__"bank_under");
        set_link_exit_dir("west");
        set_link_exit_room(__DIR__"huang_room");
        set_entry_short("地道");
        set_entry_desc(@LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
);
        set_exit_short("地道");
        set_exit_desc(@LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
);
        set_maze_room_short("地道");
        set_maze_room_desc(@LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
);
        set_outdoors(0);
}
