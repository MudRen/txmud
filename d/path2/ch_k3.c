// Room: /d/path2/ch_k3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ���ٵ������Ը��ⷱ����·�ϸ��ָ���������������
���ﲻ�����ǳ����֡���ʱ�������������߷ɳ۶���������һ
·������·��������һƬƬ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k2",
  "south" : __DIR__"ch_k4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
