// Room: /d/path5/kch43.c

inherit ROOM;

void create()
{
	set("short", "山下草地");
	set("long", @LONG
这是青城山下的一片草地，草儿长得十分茂盛，中间还夹杂
着一朵朵野花，一遍万紫千红的景象。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch44",
  "east" : __DIR__"kch42",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
