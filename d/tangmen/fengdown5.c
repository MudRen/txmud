// Room: /d/tangmen/fengdown5.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ɽ�ȵĹȵף������ĵ�û��һ�����졣��ڵ�������
ɢ�������ι�״��Сɽʯ����Щʯͷ���ܼ��������������涫��
����ġ�������һСƬ�Ͱ��Ĺ�ľ�ԡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fengd1",
  "south" : __DIR__"fengdown4",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
