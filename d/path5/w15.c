// Room: /d/path5/w15.c

inherit VRM_SERVER;

void create()
{
	set_inherit_room( ROOM );

	set_maze_long(5);

	//入口方向(出口在对面)
	set_entry_dir("east");

	//入口与区域的连接方向
	set_link_entry_dir("east");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"w14");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"w16");

	//入口房间短描述
	set_entry_short("高原小路");

	set_entry_desc(@LONG
这是一条荒凉的高原小路，路面向西斜上。路的两边都是半
人高的杂草，还有一些不知名的野花。你走到这里，不禁觉得有
些危险，不由得加快了脚步。
LONG
);

	//出口房间短描述
	set_exit_short("高原小路");

	set_exit_desc(@LONG
这是一条荒凉的高原小路，路面向西斜上。路的两边都是半
人高的杂草，还有许多不知名的野花。你走到这里，不禁觉得有
些危险，不由得加快了脚步。
LONG
);


	//迷宫房间的短描述
	set_maze_room_short("高原杂道");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一条荒凉的高原杂道，道路两边都是半人高的杂草，风
一吹地，道路淹没其中。你走到这里，看不到丝毫的为烟，不由
得加快了脚步。
LONG
);

	// 迷宫房间是否为户外房间？
	set_outdoors(1);

}
