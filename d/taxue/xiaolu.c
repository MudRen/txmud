// xiaolu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ��С��ʯ�̾͵����ѵ���ɽС·��·���Ǹߴ���յ�����
�֣�ż���ص��ż���������
LONG);
	set("outdoors", "taxue");

	set("exits", ([ 
	"south" : __DIR__"houmen",
	"north" : __DIR__"shulin",
	]));

	setup();
	replace_program(ROOM);
}
