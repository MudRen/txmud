// Room: /d/huashan/xiaolu7.c

inherit ROOM;

void create()
{
	set("short", "陡峭小路");
	set("long", @LONG
这是一条狭窄的山间小路，一旁是山崖，一旁是深涧，稍不
留神，就有可能掉下山去。白云不时从你脚下漂过，你不禁感到
有些累了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xiaolu8",
  "southeast" : __DIR__"jinsuoguan",
  "southwest":__DIR__"qitu5",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
