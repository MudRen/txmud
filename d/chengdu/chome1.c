// Room: /wiz/louth/c/chome1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ���������ã�������Ĳ��÷ǳ���ª������һ��
�������������Ǽ�����ľ�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"chenjia",
  "east" : __DIR__"chome3",
  "north" : __DIR__"chome2",
]));

	set("objects", ([
	__DIR__"npc/lu" : 1,
]));

	setup();
	replace_program(ROOM);
}
