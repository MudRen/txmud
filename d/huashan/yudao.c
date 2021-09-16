// Room: /d/huashan/yudao.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
你走到这里，只见白云缭绕，山崖高耸。风儿吹过，你不禁
晃了一晃，仿佛要把你吹倒。你侧目一看，两边悬崖深不见底，
不禁吓了一跳。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"mingya",
  "southdown" : __DIR__"xiaolu9",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
