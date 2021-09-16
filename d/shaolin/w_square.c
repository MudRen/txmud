// Room: /d/shaolin/w_square.c

inherit ROOM;

void create()
{
	set("short", "西广场");
	set("long", @LONG
这里是少林寺的西广场，广场四周是汉白玉栏杆，不知那一
代皇上下令修的。正中有一尊巨大的韦陀神像，双手端着降魔宝
杵。常年在外的行脚僧一看到这种韦陀像就知道，这里是可以留
宿的寺院。从西广场向西是六祖庙，向东是中院广场，向北是过
道，往南也是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lroad2",
  "north" : __DIR__"lroad3",
  "east" : __DIR__"m_square",
  "west" : __DIR__"6zumiao",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
