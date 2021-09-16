// Room: /d/huashan/lin2.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
茂密的树林间隐露出一条小路。四周除了陡峭的山林看不到
任何东西。路边草丛中绽放着几朵野花，只可惜你叫不出名字。
路越来越难走了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"xiaolu2",
  "southdown" : __DIR__"qiting",
  "northeast" : __DIR__"xiaolu5",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
