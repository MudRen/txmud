// Room: /d/shaolin/lroad4.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是少林寺的过道，地处后院，香客们一般是不允许来引
的，小碎石铺成的小径显的格处的幽静。小径上生满了青苔，你
走路时需要特别小心，否则一不留神会摔倒的。从这里向北是过
过道，向西是普贤殿，向东南是青石甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yongdao4",
  "north" : __DIR__"lroad5",
  "west" : __DIR__"puxian",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
