// Room: /d/path5/kch42.c

inherit ROOM;

void create()
{
	set("short", "青城山山脚");
	set("long", @LONG
这里是青城山南面的山脚。只见山势挺拔，险峻万分。你检
查了一下身上的干粮袋，看看是否充足，要不万一迷了路可不好
办。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kch43",
  "northup" : __DIR__"kch41",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
