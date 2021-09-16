// hz_maze.c 杭州北边的竹林迷宫

inherit VRM_SERVER;

void create()
{
        set_inherit_room(ROOM);
        set_maze_long(15);
        set_entry_dir("east");
        set_link_entry_dir("east");
        set_link_entry_room(__DIR__"room");
        set_link_exit_dir("west");
        set_link_exit_room(__DIR__"room");
        set_entry_short("竹林");
        set_entry_desc(@LONG
你现在身处一片茂盛的竹林中。西边是更一大片碧绿的竹林，
你敢说那几乎比杭州城都不小。东边是竹笠坡，看来那里竹笠的
名气还是要来自于这天赐的竹林啊。
LONG
);
        set_exit_short("竹林");
        set_exit_desc(@LONG
你终于走出了那见鬼的竹林。要不是运气好，你可能就迷失在那
片竹林里了。长吁一口气后，你似乎看到西边有一间草屋。
LONG
);
        set_maze_room_short("竹林");
        set_maze_room_desc(@LONG
你穿梭于一片繁茂的竹林之中。你眼中只有绿色的竹，甚至
抬起头连天都看不到。环顾四方，你根本难以辨清方向。
LONG
);
        set_outdoors(1);
}
