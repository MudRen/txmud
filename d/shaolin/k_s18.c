// Room: /wiz/uudd/path2/k_s18.c

inherit ROOM;

void create()
{
	set("short", "少室村南口");
	set("long", @LONG
这是一座村庄的南首，路旁边立着一块残旧的石碑，你走上
前去仔细看了看，依稀可以分辨出上面刻着“少室村”三个大字，
石碑下首好像还刻了很多小字，但已经风化的不成样子了。北边
坐落着十来户人家，这儿只是一个很小的村庄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s19",
  "north" : __DIR__"k_s17",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
