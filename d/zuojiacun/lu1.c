// Room: /d/zuojiacun/lu1.c

inherit ROOM;

void create()
{
	set("short", "左家村口");
	set("long", @LONG
这里就是左家村了，在这靠近渤海湾的小村子里，多数村民
都是以捕鱼为生。一般情况下，当男人外出打鱼的时候，女人们
则在家里忙一些家务，还要为男人准备饭菜。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/path1/zjz9",
  "east" : __DIR__"lu2",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
