// Room: /u/w/wangs/b/kai171.c

inherit ROOM;

void create()
{
	set("short", "��ͬ��");
	set("long", @LONG
��ͬ��λ�ڿ����֮���ϣ������ǿ������ƶ����һ�ǡ�ס
�������Щƶ���˼ҡ���ͬ���߶�����ӣ�����Щ��Ӽ���û��
һ���������ġ����ӵ��������Ĺ�����Ӫ����������ף�ʹ
������ͬ��������ֱ�����˼������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"kai174",
  "south" : __DIR__"kai164",
  "west" : __DIR__"kai172",
]));

	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
