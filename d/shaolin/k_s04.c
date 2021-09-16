// Room: /wiz/uudd/path2/k_s04.c

inherit ROOM;

void create()
{
	set("short", "龙沟");
	set("long", @LONG
这是一个长满绿树的小山沟。山沟地势低洼，这里的树木为
争夺阳光，便长得特别高大，而被树冠蔽遮的山谷就显得特别的
阴暗潮湿，因此谷中除了这些高大的乔木外，竟然是寸草不生，
地上只有一些青苔、白菌之类的植物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"k_s05",
  "east" : __DIR__"k_s03",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
