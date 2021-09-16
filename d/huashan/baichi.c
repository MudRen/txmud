// Room: /d/huashan/baichi.c

inherit ROOM;

void create()
{
	set("short", "百尺峡");
	set("long", @LONG
百尺峡，峡宽百余尺。你走在两山之，只见两侧危崖如削，
你脚下的石梯逐次向东蜿蜒盘山而去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qunxian",
  "westdown" : __DIR__"qianchi",
]));
        set("outdoors", "huashan"); 
	setup();
	replace_program(ROOM);
}
