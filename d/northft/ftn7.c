// Room: /d/northft/ftn7.c

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
  "eastup" : __DIR__"ftn8",
  "southwest" : __DIR__"ftn6",
]));

	set("outdoors", "northft");
	setup();
	replace_program(ROOM);
}
