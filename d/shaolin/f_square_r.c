// Room: /d/shaolin/f_square_r.c

inherit ROOM;

void create()
{
	set("short", "�㳡�Ҳ�");
	set("long", @LONG
�����������µĹ㳡�Ҳ࣬��һ�����µ�ɮ����ϰ��ĵط���
�������������Ľ�ӡ�������ֵ����ǳ�������������ʱ���µģ�
�������ֵ��ӣ�������ϰ��ʦ�����̵��޺���ȭ��������������
�㳡ǰԺ�����Ǵ����ã������ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"rroad1",
  "east" : __DIR__"ciyuntang",
  "west" : __DIR__"f_square",
]));

	set("objects",([
	__DIR__"npc/juewu" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
