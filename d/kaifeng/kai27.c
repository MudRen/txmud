// Room: /u/w/wangs/b/kai27.c

inherit ROOM;

void create()
{
    set("short", "����·");
	set("long", @LONG
����·ȫ����ʯ�̾ͣ���������һ��ֱͦ����������������
������һƬ�������С�·�����˽�Ϊϡ�٣���Ϊ�����Ƕ�æ�ŵ�
������׬Ǯȥ�ˣ�Ů�����ڼ��вٳּ���ֻ���������ǲ��ܳ�
��һ��������㳡����Ϣ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai29",
  "south" : __DIR__"kai25",
  "west" : __DIR__"kai28",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
