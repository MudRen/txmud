// Room: /wiz/louth/a/yu58.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road1",
  "southup" : __DIR__"yu59",
  "north" : __DIR__"yu57",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
