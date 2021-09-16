// Room: /d/fengtian/wo.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
将军休息的地方，也是将军元配夫人袁氏的卧房，袁氏嫁给
将军多年，夫妻也相敬如宾，不过袁氏一直没有子嗣，所以将军
后来又娶了二姨太。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf5",
  "west" : __DIR__ "er",
]));

	setup();
	replace_program(ROOM);
}
