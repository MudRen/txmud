// Room: /d/hangzhou/spath3.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ���ּ�С·����ֻ�ܴӵ��ϱ�̤����Ӳ���ʶ��ǰ��
�ķ��򡣺�Ȼһֻ��֪���Ķ���������ǰ�ܹ���������һ������
�Ϸ������ֶ��ж��棬�㲻�ɵò�С�Ľ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath4",
  "north" : __DIR__"stree3",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
