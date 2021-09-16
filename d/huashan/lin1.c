// Room: /d/huashan/lin1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
茂密的树林间隐露出一条小路。四周除了陡峭的山林看不到
任何东西。路边草丛中绽放着几朵野花，只可惜你叫不出名字。
再住上就要到孝子峰了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"yy_dong",
  "northwest" : __DIR__"xiaozi_feng",
  "southeast" : __DIR__"xiaolu2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
