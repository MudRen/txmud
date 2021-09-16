// Room: /wiz/uudd/path2/k_s09.c

inherit ROOM;

void create()
{
	set("short", "少室村东口");
	set("long", @LONG
这是一座村庄的东首，路旁边立着一块残旧的石碑，你走上
前去仔细看了看，依稀可以分辨出上面刻着“少室村”三个大字，
石碑下首好像还刻了很多小字，但已经风化的不成样子了。东边
坐落着十来户人家，这儿只是一个很小的村庄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_s10",
  "east" : __DIR__"k_s08",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
