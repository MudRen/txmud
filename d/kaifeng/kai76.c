// Room: /u/w/wangs/b/kai76.c

inherit ROOM;

void create()
{
	set("short", "���Ľ�");
	set("long", @LONG
���Ľ��ǿ��⸮����ĵ��򣬽ֵ�һ�����������Ĺ㳡��
��һ�������������ӿ�볱�����ǵ�����䣬��������������
������磬����С�ԡ�̯����������ڴˣ�ʵΪ����һ���쾰��
���Ե������ְ��������Ľֽ��������Χ������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai79",
  "south" : __DIR__"kai137",
  "west" : __DIR__"kai75",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
