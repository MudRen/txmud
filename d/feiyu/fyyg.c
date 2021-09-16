// Room: /wiz/louth/a/fyyg.c

inherit ROOM;

void create()
{
	set("short", "风雅阁");
	set("long", @LONG
这是一间布置淡雅的小厅，西面和北面挂着薄薄的烟绿纱帐，
中间是一张红木八仙桌，桌子上摆着一架古琴。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hqinshi.c",
  "out" : __DIR__"yu53",
  "west" : __DIR__"hxiaoyuan.c",
]));
	set(SAFE_ENV,1);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huaner" : 1,
]));

	setup();
	replace_program(ROOM);
}
