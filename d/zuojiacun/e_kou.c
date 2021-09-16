// Room: /d/zuojiacun/e_kou.c

inherit ROOM;

void create()
{
	set("short", "左家村东口");
	set("long", @LONG
这里就是左家村了，原来路边坚着的一个路牌不知被谁碰倒
了。一条坑坑洼洼的泥泞小路，你一脚深一脚浅地走在上面，心
中不禁暗骂这“破鬼地方”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu15",
  "east" : "/d/path1/zjz10",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
