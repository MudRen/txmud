// Room: /d/huashan/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
沿山路再向北就是毛女洞了，不过听山里的住民说这个毛女
洞近几十年来并不太平。进去的人没有一个能出来，所以里面到
底有些什么也就无人知道了。向东是一道架在两山之间的栈桥，
通向华山派的采石厂。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"santai",
  "north" : __DIR__"maonv",
  "east":__DIR__"zhanqiao",
]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
