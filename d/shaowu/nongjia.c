// Room: /d/shaowu/nongjia.c

inherit ROOM;

void create()
{
	set("short", "ũ��Ժ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tulu1",
]));

	setup();
	replace_program(ROOM);
}
