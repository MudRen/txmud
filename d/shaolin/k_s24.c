// Room: /wiz/uudd/path2/k_s24.c

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这里是一片空地，看起来这里是夏天乘凉的好去处，过了
这里就是一段土路了。你加快了脚步。�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/shaolin/tulu3",
  "southeast" : __DIR__"k_s23",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
