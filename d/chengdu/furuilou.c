// Room: /wiz/louth/c/furuilou.c

inherit ROOM;
inherit SHOW_MSG;

void create()
{
	set("short", "��ܽ��¥");
	set("long", @LONG
�����ǳɶ��������ľ�¥����ܽ��¥��������ٹ��ˣ�����
С��֮�ң����Ѿۻᡢϲ����ϯ����������ٰ졣����ܽ¥Ҳ��
�������������������ɶ��İ��հ��������֡�
LONG
);

	set("night_long",@LONG
�����ǳɶ��������ľ�¥����ܽ��¥�������Ѿ������ˣ���
��������Ѳ������ڡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fdjie3",
  "west" : __DIR__"chufang",
]));

	set_master("pao tang");

	set("no_fight", 1);
	set("valid_startroom", 1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));
	setup();
	load_board("board_chengdu");
}
