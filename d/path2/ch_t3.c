// Room: /d/path2/ch_t3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
���ǳ�����������Ĵ�������Ը��ⷱ����·�ϸ��ָ�����
�������������ﲻ�����ǳ����֡���ʱ�������������߷ɳ۶�
��������һ·������·��������һƬƬ�����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t2",
  "west" : __DIR__"ch_t4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
