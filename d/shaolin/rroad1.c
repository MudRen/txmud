// Room: /d/shaolin/rroad1.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ����");
	set("long", @LONG
�����������µ�ǰԺ���������ߵĴ��ǽ��д�С����֣�
�Եúܹ��ӡ��ڲ�Զ���Ĳ�ƺ������ֻ��ȸ���ڵ������ţ�����
ǰ�������Դ����ɮ���͸����ֵġ����������Ǳ��֣�������
ǰԺ�㳡���Ҳࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f_square_r",
  "north" : __DIR__"rroad2",
  "east" : __DIR__"beilin1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
