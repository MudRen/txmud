// Room: /wiz/louth/a/ting.c

inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);

	set(SAFE_ENV,1);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yedie" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi5",
]));

	setup();
	replace_program(ROOM);
}
