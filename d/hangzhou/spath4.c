// Room: /d/hangzhou/spath4.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ���ּ�С·����ֻ�ܴӵ��ϱ�̤����Ӳ���ʶ��ǰ��
�ķ��򡣺�Ȼһֻ��֪���Ķ���������ǰ�ܹ���������һ������
�Ϸ������ֶ��ж��棬�㲻�ɵò�С�Ľ�����������������¶��
һ��é�ݡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"spath5",
  "east" : __DIR__"shouse1",
  "north" : __DIR__"spath3",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
