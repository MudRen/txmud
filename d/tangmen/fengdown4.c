// Room: /d/tangmen/fengdown4.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ɽ�ȵĹȵף������ĵ�û��һ�����졣��ڵ�������
ɢ�������ι�״��Сɽʯ����Щʯͷ���ܼ��������������涫��
����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"fengdown5",
  "south" : __DIR__"fengdown3",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
