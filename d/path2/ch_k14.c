// Room: /d/path2/ch_k14.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·���Ӳݴ�������������ȥ��ֻ��һƬ
������·�����˺��٣�ż���м���ũ�����ŵ��Ӿ�������������
Զ�����Ǻ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"ch_k13",
	"west" : "/d/houmaji",
	"northeast" : __DIR__"q1",
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
