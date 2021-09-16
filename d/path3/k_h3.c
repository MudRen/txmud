// Room: /d/path3/k_h3.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走到这里，只见路面虽然不十分宽阔，但也还算整齐。时
不时有快马奔驰而过，带起阵阵尘土。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_h2",
  "east" : __DIR__"k_h4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
