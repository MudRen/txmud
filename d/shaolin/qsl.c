// Room: /d/shaolin/qsl.c

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM );

	//迷宫房间里的怪物。
	//set_maze_npcs(__DIR__"npc/snake");

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("east");

	//入口与区域的连接方向
	set_link_entry_dir("east");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"qhs2");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"qhs3");

	//入口房间短描述
	set_entry_short("灌木丛");

	//入口房间描述
	set_entry_desc(@LONG
这里是一片浓密的小灌木丛，东北方向远远望去是一处宏大
的寺庙。一阵山风吹来四周沙沙做响，给人一种阴森恐怖的感觉。
LONG
);

	//出口房间短描述
	set_exit_short("灌木丛");

	//出口房间描述
	set_exit_desc(@LONG
这里是一片浓密的小灌木丛，东北方向远远望去是一处宏大
的寺庙。一阵山风吹来四周沙沙做响，给人一种阴森恐怖的感觉。
LONG
);
/*
	//迷宫房间的短描述
	set_maze_room_short("灌木丛");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这里是一片浓密的小灌木丛，东北方向远远望去是一处宏大
的寺庙。一阵山风吹来四周沙沙做响，给人一种阴森恐怖的感觉。
LONG
);
*/

	// 迷宫房间是否为户外房间？
	set_outdoors(1);

	set_valid_rooms( ({
	__DIR__"qsl_snake",
	__DIR__"qsl_snake",
	__DIR__"qsl_room",
}));
}
