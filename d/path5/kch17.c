// Room: /d/path5/kch17.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
��������ʯ�£���֪����һ��ɽ�廬����͵ġ��Ų���ȥ��
һ�󻬶����������������졣ʯ���������ų������̵�С�ݣ���
�����˾������ɵ����뵽��������ǿ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch18",
  "northup" : __DIR__"kch16",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
