// Room: /d/tangmen/xiaoyuan.c

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
������һ���ž���СԺ�䣬��Χ�����������͵���ʣ�����
�������̵�С�ݣ�Ժ���������һ��԰ʯ�������ӱ����м���ʯ
�⣬ʯ����ʯ����涼�ǳ��⻬�����񾭳������������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gd1",
  "south" : __DIR__"bridge1",
  "east" : __DIR__"lawn",
  "west" : __DIR__"well",
]));

	set("outdoors", "tangmen");

	setup();
	replace_program(ROOM);
}
