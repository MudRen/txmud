// Room: /d/path3/k_h39.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʯ�̳ɵĹٵ�����·�������������Ե�ʮ����
�֡�·�������в��ٵ�̯��������������������Ľ����ţ�����
ʱ���������ָָ��㣬�����ڽ����ȥ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h40",
  "north" : __DIR__"k_h38",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
