// Room: /u/w/wangs/a/yu52.c

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
  "north" : __DIR__"yu53",
  "south" : __DIR__"yu51",
  "east" : __DIR__"yu66",
]));
 
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
