// Room: /d/path2/ch_k33.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ����������ϣ�·�������ǹ�ͺͺ��ɽ����ƽ��
�����ϡϡ����������һЩׯ�ڡ�ԶԶ��ȥ��һ���ŵ�Ҥ��ǰ��
һЩ����������ˣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k32",
  "south" : __DIR__"ch_k34",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
