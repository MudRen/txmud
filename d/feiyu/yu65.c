// Room: /u/w/wangs/a/yu65.c

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
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yu64",
  "north" : __DIR__"yu66",
  "west" : __DIR__"yu64",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
