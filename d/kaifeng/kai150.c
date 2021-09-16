// Room: /u/w/wangs/b/kai150.c

inherit ROOM;

void create()
{
	set("short", "镖局大厅");
	set("long", @LONG
厅堂中的陈设，全是十分精致的紫檀木家具，单是那扇巨大
的八摺屏风，上面镶满了各色宝玉，砌成极其生动的八仙图，已
是罕见的古物。左右各摆四张太师椅，是为来客准备的。大厅的
左右两边各有一个偏厅。偏厅里住的是一些镖师和下人。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai149",
  "north" : __DIR__"kai155",
  "west" : __DIR__"kai154",
  "east" : __DIR__"kai153",
]));
        set("objects",([
        __DIR__"npc/wubt": 1,
]));

	setup();
	replace_program(ROOM);
}
