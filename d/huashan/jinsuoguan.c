// Room: /d/huashan/jinsuoguan.c

inherit ROOM;

void create()
{
	set("short", "金锁关");
	set("long", @LONG
这里就是金锁关，是通往南峰、西峰、北峰的咽喉。这里三
峰环抱，外险而内幽，你置身其间，不禁如入仙境。山间一条忽
明忽暗的小溪流向山下。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"wushangdong",
  "northwest" : __DIR__"xiaolu7",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
