// Room: /d/changan/didao.c

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( LIGHT_ROOM );

	//迷宫房间里的怪物。
	//set_maze_npcs(__DIR__"npc/maque");

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("up");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"zhubao_behind");

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"under_hg");

	//入口房间短描述
	set_entry_short("地道");

	//入口房间描述
	set_entry_desc(@LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
);

	//出口房间短描述
	set_exit_short("地道");

	//出口房间描述
	set_exit_desc(@LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("地道");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这里是一条阴暗潮湿的地道，两旁的墙壁上挂着点点水珠，
地上布满了脚印，似乎经常有人从这里走过。
LONG
);

	// 迷宫房间是否为户外房间？
	//set_outdoors(1);
}
