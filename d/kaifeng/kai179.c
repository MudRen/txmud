// Room: /u/w/wangs/b/kai179.c

inherit ROOM;

void create()
{
	set("short", "��ͬ");
	set("long", @LONG
��ͬ��һ�����������ӣ������ǿ������ƶ����һ�ǡ�ס��
�����Щƶ���˼ҡ���ͬ���߶�����ӣ�����Щ��Ӽ���û��һ
���������ġ����ӵ��������Ĺ�����Ӫ����������ף�ʹ��
����ͬ��������ֱ�����˼������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai176",
  "east" : __DIR__"kai159",
]));
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
