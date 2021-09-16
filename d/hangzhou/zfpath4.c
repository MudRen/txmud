// Room: /d/hangzhou/zfpath4.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是通往府衙内堂的小路，有碎石铺成的小路非常的平整
路两旁种植着各种奇花异草，随风摇摆，沿小路向北就是内堂了
向南则是一个小小的花园。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zfchaifang",
  "south" : __DIR__"zfgarden",
  "east" : __DIR__"zfpath6",
  "north" : __DIR__"zfpath5",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
