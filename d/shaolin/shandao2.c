// Room: /d/shaolin/shandao2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��������ɽ·��ɽ·�����Ƕ��͵�ɽ�£�������һ��
�޼ʵ����֡�·�Ͼ����ܿ�������ɮ����������������һֱ�߾�
���������������ˣ���Լ���������ͳ����о�����
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shandao3",
  "northeast" : __DIR__"shandao1",
]));

	set("objects",([
	__DIR__"npc/butterfly" : 1,
]));
	setup();
	replace_program(ROOM);
}
