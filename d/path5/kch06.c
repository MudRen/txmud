// Room: /d/path5/kch06.c

inherit ROOM;

void create()
{
	set("short", "���ɽ��");
	set("long", @LONG
����������ɽ�ţ���ͺͺ��ʲô��û�У������ͱ������
��Ӱ�����ɴ����һ������С·��ɽ���ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"kch07",
  "north" : __DIR__"kch05",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
