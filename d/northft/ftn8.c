// Room: /d/northft/ftn8.c

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
  "eastup" : __DIR__"ftn9",
  "westdown" : __DIR__"ftn7",
]));

	set("outdoors", "northft");
	setup();
	replace_program(ROOM);
}
