// Room: /d/shaolin/jinnaluo.c

inherit ROOM;

void create()
{
	set("short", "�����޵�");
	set("long", @LONG
�����������µĽ����޵�����ޱ������������ˡ��˷��ˡ�
����֮�⣬�ǰ˲������෨��֮�������Ǵ�������ޣ����߹�
���������߲�������񣬺ò����ϡ������������Ƕ��㳡����
���������µ���¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhonglou1",
  "west" : __DIR__"e_square",
]));

	set("objects",([
	__DIR__"npc/kongxing" : 1,
]));

	setup();
	replace_program(ROOM);
}
