// Room: /d/northft/ftn9.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��խխ����ɽС·�����Թ�ʯ��ᾣ��м��·���Ǻ�
ƽ̹���������Ǳ���ר�ſ�������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"ftn8",
  "east" : __DIR__"ftn10",
]));

	set("outdoors", "northft");
	setup();
	replace_program(ROOM);
}
