// Room: /wiz/louth/a/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ��һ��������С·������������˵���������������
��Ƨ�������������Ѿ��ߵ��˾�ͷ����������ʲô�ر��������
������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"westup" : __DIR__"shanlu2",
	"southdown" : "/d/path1/tch_ft6",
]));

	setup();
	replace_program(ROOM);
}
