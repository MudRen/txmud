// Room: /d/feiyu/hua_pu.c

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room( ROOM );

	//迷宫房间里的怪物。
	//set_maze_npcs(__DIR__"npc/maque");

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"rukou");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"huatan");

	//入口房间短描述
	set_entry_short("栅栏门");

	//入口房间描述
	set_entry_desc(@LONG
眼前是一个竹条编成的大栅栏门，门边的竹木牌上漆着四个
娟秀的篆字“绯雨花圃”，据说是掌门人亲笔所书。南面是一条
幽静的小路，北面阵阵花香扑鼻而来，大概就是花圃了。
LONG
);

	//出口房间短描述
	set_exit_short("百花圃");

	//出口房间描述
	set_exit_desc(@LONG
这是一处巨大的花圃，花圃里四季都开放这个色的鲜花，据
说这个花圃只有掌门的贴身仆人逾二嫂才能维护。绯雨阁的掌门
也经常来到这里赏花散心。北面是一个小花坛。
LONG
);

/*
	//迷宫房间的短描述
	set_maze_room_short("竹林");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一片浓密的翠竹林，小鸟的鸣叫声和风吹过竹林的沙沙
声交织成美丽的大自然的旋律。地上杂草丛生说明这里很少有人
来。粗壮的翠竹笔直向上，这就是天下闻名的南翠竹。
LONG
);
*/
	// 迷宫房间是否为户外房间？
	set_outdoors(1);


	set_valid_rooms( ({
	__DIR__"pu",
	__DIR__"pu",
	__DIR__"pu",
	__DIR__"pu_hua",
	__DIR__"pu_cao",
	__DIR__"pu_guo",
}));

}
