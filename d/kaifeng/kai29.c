// Room: /u/w/wangs/b/kai29.c

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
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai27",
  "west" : __DIR__"kai30",
  "east" : __DIR__"kai32",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
