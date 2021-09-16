// Room: /wiz/louth/a/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是山边一条长长的小路，好象很少有人到这里来过，很是
静僻。不过你现在已经走到了尽头，看不见有什么特别的事物在
附近。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"westup" : __DIR__"shanlu2",
	"southdown" : "/d/path1/tch_ft6",
]));

	setup();
	replace_program(ROOM);
}
