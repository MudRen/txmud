// Room: doorgd.c by pian
inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long",@LONG
这里就是紫霞宫兵器室，四下里很是干净，各种兵器整齐地
放在兵器架上，兵器多没有锋刃，看来只是供练功用的。本派弟
子可以到这里取合手的兵器去练习。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"guodaow2",
]));

	set("objects",([
	WEAPON_DIR"thin_sword" : 5,
	WEAPON_DIR"bamboo_sword" : 3,
]));

	setup();
	replace_program(ROOM);
}