// Room: /d/hangzhou/out_hangzhou_s.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
������ͳ��˺��ݳǡ������Ǻ��ݳǵ����ż����پ����̲�
�Ź��������ˡ��ǵ�������һ�����������
LONG
	);

/*
	set("GATE_ROOM", 1);
	set("gate_name", "���ݳ�����");
	set("gate_dir", ([
  "north" : __DIR__"southdoor",
]));
	set("close_look", "�����Ǻ��ݳ��⡣������һ��������·�����ǳ����ǵ���
�ţ������Ѿ������ˡ�
");
*/

	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"spath1",
	"north" : __DIR__"southdoor",
]));

	setup();
	replace_program(ROOM);
}
