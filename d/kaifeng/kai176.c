// Room: /u/w/wangs/b/kai176.c

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
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai177",
  "west" : __DIR__"kai178",
  "southwest" : __DIR__"kai174",
  "east" : __DIR__"kai179",
]));

	setup();
	replace_program(ROOM);
}
