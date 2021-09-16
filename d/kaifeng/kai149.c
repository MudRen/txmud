// Room: /u/w/wangs/b/kai149.c

inherit ROOM;

void create()
{
	set("short", "镖局大院");
	set("long", @LONG
院子里面堆放着十几辆用草席盖着的空镖车，草席上积满了
雪，东面的屋檐下，斜插着一面酱色镶金边的镖旗，被风吹得蜡
蜡作响，使人几乎分辨不出用金线绣在那上面的是老虎，还是狮
子。大院里不时有穿着羊皮袄的镖师进出，有的喝了几杯酒，就
故意敞开衣襟，好像在表示他们不怕冷。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai150",
  "south" : __DIR__"kai142",
  "west" : __DIR__"kai152",
  "east" : __DIR__"kai151",
]));
        set("objects",([
        __DIR__"npc/wb": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
