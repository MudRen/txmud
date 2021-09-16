// Room: /d/tianshui/hole.c

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( LIGHT_ROOM );

	//迷宫房间里的怪物。
	//set_maze_npcs(__DIR__"npc/maque");

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"enter_hole");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"xianjing_entry");

	//入口房间短描述
	set_entry_short("洞内");

	//入口房间描述
	set_entry_desc(@LONG
这是一个阴森森的大山洞，里面洞套洞、洞连洞，简直像一
个迷魂阵。石壁上渗出点点水珠，地上非常泥泞。
LONG
);

	//出口房间短描述
	set_exit_short("洞内");

	//出口房间描述
	set_exit_desc(@LONG
这是一个阴森森的大山洞，里面洞套洞、洞连洞，简直像一
个迷魂阵。石壁上渗出点点水珠，地上非常泥泞。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("洞内");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一个阴森森的大山洞，里面洞套洞、洞连洞，简直像一
个迷魂阵。石壁上渗出点点水珠，地上非常泥泞。
LONG
);

	// 迷宫房间是否为户外房间？
	//set_outdoors(1);
}
