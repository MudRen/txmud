// Room: /u/w/wangs/b/kai74.c

inherit ROOM;

void create()
{
	set("short", "中心广场");
	set("long", @LONG
开封府的广场建造得委实壮观非常，方圆数百丈的空地全部
是用一块块坚硬的花岗岩铺就，广场中央是三层雕栏围起的一座
圆型祭坛，一只丈把高的青铜巨鼎立于其上，使得空旷的广场气
象森严，令人叹为观止。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai95",
  "north" : __DIR__"kai75",
  "west" : __DIR__"kai71",
  "east" : __DIR__"kai137",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
