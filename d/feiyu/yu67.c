// Room: /u/w/wangs/a/yu67.c

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
  "south" : __DIR__"yu64",
  "north" : __DIR__"yu64",
  "west" : __DIR__"yu57",
  "east" : __DIR__"yu100",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
