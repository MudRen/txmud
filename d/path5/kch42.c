// Room: /d/path5/kch42.c

inherit ROOM;

void create()
{
	set("short", "���ɽɽ��");
	set("long", @LONG
���������ɽ�����ɽ�š�ֻ��ɽ��ͦ�Σ��վ���֡����
����һ�����ϵĸ������������Ƿ���㣬Ҫ����һ����·�ɲ���
�졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kch43",
  "northup" : __DIR__"kch41",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
