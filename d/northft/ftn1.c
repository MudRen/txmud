// Room: /d/northft/ftn1.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
���Ƿ���Ǳ�����һ����ʯ�̳ɵ�С·��������Ƿ���ǵ�
�����ˡ�·��ϡ��ĳ���һЩ�Ĳݣ�·������ɳ�������󱱷��
Х������Խ������һ�������ĸо���
LONG
	);
	set("exits", ([
  "south" : "/d/fengtian/out_fengtian_n",
  "north" : __DIR__"ftn2",
]));

	set("outdoors", "northft");

	setup();
}
