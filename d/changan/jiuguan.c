// Room: /d/changan/jiuguan.c

inherit ROOM;

void create()
{
	set("short", "小酒馆");
	set("long", @LONG
这是一间破旧简陋的小酒馆，里面摆着几张木桌椅，客人们
要的酒菜也很简单，大概都是周围的贫民经常光顾这里。
LONG
	);
	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad7",
]));

	set("objects",([
	__DIR__"npc/tiezui" : 1,
]));

	setup();
	replace_program(ROOM);
}
