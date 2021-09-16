// Room: /wiz/uudd/path2/woodfac.c

inherit ROOM;

void create()
{
	set("short", "伐木场工作站");
	set("long", @LONG
这是一间很普通的伐木厂，几个伐木工人正在用力的锯着一
根根粗大的圆木，另外有几个人正在刨着木条，一个工人看见了
你，对着你点了一下头，又埋下头继续手头的工作。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k_s14",
]));

	setup();
	replace_program(ROOM);
}
