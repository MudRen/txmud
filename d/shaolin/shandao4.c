// Room: /d/shaolin/shandao4.c

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

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shandao3",
  "southdown" : __DIR__"shandao5",
]));

	set("objects",([
	__DIR__"npc/xiangke" : 2,
]));

	setup();
	replace_program(ROOM);
}
