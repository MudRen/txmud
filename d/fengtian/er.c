// Room: /d/fengtian/er.c

inherit ROOM;

void create()
{
	set("short", "二姨太房");
	set("long", @LONG
二姨太李氏就住在这里，将军元配夫人一直没有子嗣，所以
将军娶了李氏，李氏人长的到很端庄秀丽，不过也是个小家碧玉
，不是很有见识，不过很会讨将军欢心。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wo",
]));

	setup();
	replace_program(ROOM);
}
