// Room: /u/w/wangs/b/kai141.c

inherit ROOM;

void create()
{
	set("short", "���ⶫ��");
	set("long", @LONG
������ֺ�ᶫ�����ѿ���Ƿֳ����롣·����������������
�ܶ������Ǻ�«�ġ���ζС�Ե�С�̷����ؽֽ���������������
�ϣ������и��ܵ��������ķ�����������·�ϱ���һ����ԡի��
���������������ǵ������ھ֣���������Զ�������Ľ��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai143",
  "north" : __DIR__"kai142",
  "west" : __DIR__"kai138",
  "east" : __DIR__"kai144",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
