// Room: /d/shaolin/lroad1.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ����");
	set("long", @LONG
�����������µ�ǰԺ�������������������ź�����������ģ�
������һ��Сˮ�أ���������������ˮ������Ȼ�������˲�����
����ɫ��Ҳû����������פ�㡣������·����ɮ�˶��ǴҴ�ææ
�ġ������������ǹ����֣����ǹ�������Զ���������ǹ㳡��
�ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f_square_l",
  "north" : __DIR__"lroad2",
  "west" : __DIR__"gongde1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
