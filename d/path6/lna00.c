// Room: /d/path6/lna00.c

inherit VRM_SERVER;

void create()
{
	set_inherit_room( DANGER_ROAD );

//	set_maze_npcs(__DIR__"npc/maque");

	set_maze_long(30);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"lna01");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"lna02");

	//入口房间短描述
	set_entry_short("高原山区回廊入口");

	set_entry_desc(@LONG
这里是西藏高原山区回廊的入口，放眼望去，黄色的山脉显
露着红色。这里空气稀薄，寒风凛冽，你来到这里，忍不住心里
泛起了犹豫。像这种地方，没十足把握还是不去的好。
LONG
);

	//出口房间短描述
	set_exit_short("高原山区回廊出口");

	set_exit_desc(@LONG
这里是西藏高原山区回廊的出口，放眼望去，黄色的山脉显
露着红色。这里空气稀薄，寒风凛冽，你来到这里，忍不住心里
泛起了犹豫。像这种地方，没十足把握还是不去的好。
LONG
);


	//迷宫房间的短描述
	set_maze_room_short("高原回廊");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这里就是西藏东部的高原山区回廊，你走到这里，只见四周
一望无际，全都黄红的山地。凛冽的山风吹过，身体忽然感到一
阵凉意。你刚要举步，却不知该走向何方。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(1);

}
