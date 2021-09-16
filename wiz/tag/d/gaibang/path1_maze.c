// path1_maze.c

inherit VRM_SERVER;

void create()
{
        set_inherit_room(ROOM);
        set_maze_long(40);
        set_maze_npcs(__DIR__"npc/maze_snake");
        set_entry_dir("south");
        set_link_entry_dir("southeast");
        set_link_entry_room("/wiz/tag/d/path1/tch_ft17");
        set_link_exit_dir("north");
        set_link_exit_room(__DIR__"path1_maze_hut");
        set_entry_short("树林");
        set_entry_desc(@LONG
你面前是一片茂密的树林，连边际都看不到。听说那就是蛇
林了，里面到处都是蛇，你犹豫着要不要进去看看。
LONG
);
        set_exit_short("树林");
        set_exit_desc(@LONG
你来到了树林的边缘，这里的树已经很稀疏了，估计也不会
再有蛇了。
LONG
);
        set_maze_room_short("树林");
        set_maze_room_desc(@LONG
你现在身处密林之中，四周围除了绿色什么都看不到。当然，
蛇也是绿的，你很难分清到底四周围是不是有蛇，只有加倍小心
提防了。
LONG
);
        set_outdoors(1);
}
