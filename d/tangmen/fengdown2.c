// Room: /d/tangmen/fengdown2.c

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
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"fengdown3",
  "east" : __DIR__"fengdown1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
