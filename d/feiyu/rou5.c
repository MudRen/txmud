// Room: /wiz/louth/a/rou5.c

inherit ROOM;

void create()
{
	set("short", "Сľ��");
	set("long", @LONG
����һ����ԭľ���ɵ�Сľ�ţ������������̶����ǳ���̣�
���µ�Ϫˮ�峺���ס�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rou6",
  "west" : __DIR__"rou1",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
