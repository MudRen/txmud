// Room: /u/w/wangs/b/kai19.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ�򿪷���ڵ�һЩ���о��㣬���·����ȫ������
�������Ĵ�����·��żȻ�ܿ���������������ο�������·�ߵ�
����ָָ��㡣�����Ǻ���·�ľ�ͷ�ˣ������Ƿ羰�续������
ʤ�أ�������һ���ں�����С�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai16",
  "west" : __DIR__"kai20",
  "east" : __DIR__"kai21",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
