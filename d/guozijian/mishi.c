// /d/guozijian/mishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ�Ӻ������ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"dianzhong",
]));

	set("objects",([
		__DIR__"obj/key":1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}