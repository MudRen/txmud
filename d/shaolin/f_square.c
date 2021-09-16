// Room: /d/shaolin/f_square.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ�㳡");
	set("long", @LONG
�����������µĹ㳡ǰԺ�����ǿ��������Կ����ܶ��̨��
���������ţ�̨�׵ľ�ͷ��ϡ��������㳡���������޴��ˮ
�ף�������������ˮ�����Է������Ż���õġ��������������
�����ϣ��������������䣬Ҳ���ܵ����յĸ�Ⱦ�ġ�������
�����ǹ㳡����࣬���ǹ㳡���Ҳ࣬������̨�ף��ϱ���ɽ
�š�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"door",
  "north" : __DIR__"taijie",
  "east" : __DIR__"f_square_r",
  "west" : __DIR__"f_square_l",
]));

	set("outdoors", "shaolin");

	setup();
	load_board("board_shaolin");
	replace_program(ROOM);
}
