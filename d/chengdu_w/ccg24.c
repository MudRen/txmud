// Room: /d/path5/ccg24.c

inherit ROOM;

void create()
{
	set("short", "ŭ������");
	set("long", @LONG
��������ȣ�С�����������ŭ�����У������Ľ�ˮ������
��ȴ��������һ����֪����С������������Ľţ�����˻��ȣ�
С������ο���һ�㣬ȴ��Ȼ�������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg25",
  "east" : __DIR__"ccg23",
]));
        set("outdoors", "chengdu_w");

        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
