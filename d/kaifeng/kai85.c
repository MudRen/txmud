// Room: /u/w/wangs/b/kai85.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
这里是一间很大的铁匠铺，屋子中央架着几个大炉子，周围
摆满了各式各样的兵器半成品。几个小伙计在忙碌着。开封由于
近邻少林寺，所以民风好武。看样子这里的生意非常好。进门的
门框上盯着一块铁牌(paizi)。
LONG
);

	set("item_desc",([
	"paizi" : "\n高价收购兵器、护甲\n代客配(pei)钥匙\n修理(xiuli)兵器。\n\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai83",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
