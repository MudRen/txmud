// Room: /d/path5/kch56.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ�����������·�ϵ����˳�������������·�����ֱ�
�����˸���С̯����ʲô�Ķ��У�ʮ�����֡���С�����������
�ǲ���������ɱ���͵��ʲô��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/chengdu/out_chengdu_n",
  "north" : __DIR__"kch55",
]));

	set("cannot_build_home", 1);
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
