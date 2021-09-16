// Room: /d/huashan/husunchou.c

inherit ROOM;

void create()
{
	set("short", "猢狲愁");
	set("long", @LONG
这里就是连猢狲都发愁的险峻崖壁。再向前去，就是华山的
北峰。俯瞰关中辽阔平原，不禁顿觉心胸阔开。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"yuntai",
  "southwest" : __DIR__"ligou",
  "southdown" : __DIR__"tianti2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
