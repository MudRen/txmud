//maple.c 枫树林迷宫

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
    set_inherit_room(ROOM);

	//迷宫房间里的怪物。
{
        if (random(11)>10)
    set_maze_npcs("/d/tianshui/npc/bird");
}

	//迷宫的单边长
    set_maze_long(15);

	//入口方向(出口在对面)
    set_entry_dir("north");

	//入口与区域的连接方向
    set_link_entry_dir("north");

	//入口与区域的连接档案名
    set_link_entry_room(__DIR__"maple_s");

	//出口与区域的连接方向
    set_link_exit_dir("south");

	//出口与区域的连接档案名
    set_link_exit_room(__DIR__"maple_e");

	//入口房间短描述
    set_entry_short("枫树林");

	//入口房间描述
	set_entry_desc(@LONG
这是一片火红的枫树林，只听风吹叶动，沙沙不绝，似乎
还有点水的气息。
LONG
);

	//出口房间短描述
    set_exit_short("枫树林");

	//出口房间描述
	set_exit_desc(@LONG
这是一片火红的枫树林，只听风吹叶动，沙沙不绝，似乎
还有点水的气息。
LONG
);

	//迷宫房间的短描述
    set_maze_room_short("枫树林");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一片火红的枫树林，只听风吹叶动，沙沙不绝，似乎
还有点水的气息。
LONG
);

	// 迷宫房间是否为户外房间？
        set_outdoors(1);
}
