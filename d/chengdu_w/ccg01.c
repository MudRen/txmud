// Room: /d/path5/ccg01.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʯ���̳ɵĴ�·��·�������������˺ܶ࣬��
�����С�����ؽֽ��������ֳ�һ�鷱���ľ����ɴ�������
�͵��ɶ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg02",
  "east" : "/d/chengdu/out_chengdu_w",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
