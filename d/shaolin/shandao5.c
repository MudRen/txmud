// Room: /d/shaolin/shandao5.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ֱ��ɽ·���Ϸ����죬һֱ��û������֮�У�ɽ
����������һƬһ���޼ʵ����֣������Ƕ��͵�ɽ�¡������ܿ�
������ɮ��������ˮ����Զ�ĵط���Լ������������ˮ��������
һֱ�߾����������������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"shandao4",
  "northeast" : __DIR__"shanquan",
  "southdown" : __DIR__"jjting",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
