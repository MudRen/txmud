// Room: /d/northft/ftn13.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��խխ����ɽС·�����Թ�ʯ��ᾣ��м��·���Ǻ�
ƽ̹���������Ǳ���ר�ſ�������ġ�����ȥ��һ��Ƭ��ʯ�ڡ�
LONG
	);
	set("exits", ([
	"west" : __DIR__"ftn12",
	"east" : __DIR__"iron_mine/entry",
]));

	setup();
	replace_program(ROOM);
}
