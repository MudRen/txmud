// Room: /d/shaolin/6zumiao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µ����������й���������ܵķ��񣬱̴���
�ᣬ�ϱ���һ���ʯ����������л��ܴ�ʦ���������������
��ԭ�������������̨��������һ��δ��ǳ���������������
�ǹ�¥���������㳡��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"w_square",
  "west" : __DIR__"gulou1",
]));

	set("objects",([
	__DIR__"npc/kongse" : 1,
]));

	setup();
	replace_program(ROOM);
}
