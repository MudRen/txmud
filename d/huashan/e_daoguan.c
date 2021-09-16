// Room: /d/huashan/e_daoguan.c

inherit ROOM;

void create()
{
	set("short", "东道观");
	set("long", @LONG
这里就是东道院，处虚道长当年曾在此修练。华山道教的后
世弟子都在此修习易学。如果你有缘分，或许可以碰上几个清修
的得道长老。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huixin",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
