// Room: /u/w/wangs/a/yu64.c

inherit ROOM;

void create()
{
	set("short", "÷��԰");
	set("long", @LONG
����������÷������ɫ��ǳһ���һ����ٴ�˿������״��
�������ˣ�����ʹ������÷�����Կຮ�����ľ��䣬����
����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu67",
  "north" : __DIR__"yu66",
  "west" : __DIR__"yu51",
  "east" : __DIR__"yu65",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
