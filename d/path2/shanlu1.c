// Room: /d/path2/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条崎岖的山路，路的两旁长满了灌木丛，前面一棵倒
下的横在路中，挡住了上山的道路。
LONG
	);
	set("exits", ([
//	"southeast":"/d/xueting/path1", /* sizeof() == 1 */
        "eastup" : "/d/heifeng/lu1",
  "west" : __DIR__"ch_k11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
