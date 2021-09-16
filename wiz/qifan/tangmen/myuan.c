// Room: /d/tangmen/myuan.c

inherit ROOM;

void create()
{
	set("short", "中院");
	set("long", @LONG
这里是唐家堡的内院，宽阔的院子庄严肃穆，四周的角落里
都站着一些精壮大汉在警惕的巡视。院子中央东北向摆放着两排
石礅，大概是唐家堡议事的时候给个头目坐的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yitong",
  "south" : __DIR__"gd5",
  "east" : __DIR__"ssl2",
  "west" : __DIR__"ssl1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
