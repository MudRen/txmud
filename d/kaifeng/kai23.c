// Room: /u/w/wangs/b/kai23.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
������һ�������С������Ǿ����������ĸ߸ߵ���ש
Ժǽ�������ɫ��Ժǽ�ϼ���ż��Ƚ��յĴ��š����������
�������⣬���Ը���һ������ɭɭ�ĸо����ϱ���һ��ľ���̡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai24",
  "north" : __DIR__"kai190",
  "west" : __DIR__"kai21",
  "east" : __DIR__"kai25",
]));
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
