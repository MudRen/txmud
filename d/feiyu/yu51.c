// Room: /u/w/wangs/a/yu51.c

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
  "south" : __DIR__"yu57",
  "north" : __DIR__"yu52",
  "west" : __DIR__"yu50",
  "east" : __DIR__"yu64",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
