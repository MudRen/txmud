// Room: /d/huayin/tl4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С��·��·�ϵ�������ѹ�ŵĳ��ޣ�·��û��
��������ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"northeast" : __DIR__"tl3",
	"southwest" : "/d/path2/da_hou7",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
