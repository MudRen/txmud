// Room: /u/w/wangs/b/kai159.c

inherit ROOM;

void create()
{
	set("short", "��·��");
	set("long", @LONG
����һ��������·�ڡ�������ǰ�ɽ���������������ɽ�
��ӣ�������һ��С��ͬ��ͨ�򿪷����ƶ��ĵ���������ʯ��
�̳ɡ���һ�����ɸߵ�����ϣ�������յ��ĵ�����Ϊҹ������
�����˷��㡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai160",
  "north" : __DIR__"kai158",
  "west" : __DIR__"kai179",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
