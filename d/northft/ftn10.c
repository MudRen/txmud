// Room: /d/northft/ftn10.c

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
  "east" : __DIR__"ftn11",
  "west" : __DIR__"ftn9",
]));

	set("outdoors", "northft");
	setup();
	replace_program(ROOM);
}
