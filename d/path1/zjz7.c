// Room: /d/path1/zjz7.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ���ּ�С·���������ּ�ߴߴ�����ؽ��š���һ������
ֻ�е�ʪ�����أ���Ҷ˳�ŷ��򻺻�Ʈ�䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"zjz6",
  "southeast" : __DIR__"zjz8",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
