// Room: /u/w/wangs/b/kai155.c

inherit ROOM;

void create()
{
	set("short", "镖局后院");
	set("long", @LONG
但见天马镖局的前院及厅堂尽管极尽华丽，但庄后却是一片
荒芜的破烂土地，仅有一个异常残旧的小屋，“无依无靠”地孤
立着。小屋本只以木板搭成，排得很疏，到处都是数寸宽阔的空
隙，北风“眉飞色舞”地从四方八面乘机渗入。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai150",
]));
        set("objects",([
        __DIR__"npc/tang": 1,
        __DIR__"npc/cb": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
