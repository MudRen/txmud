// Room: /d/path1/shanao.c

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
����һ����ɽ���һ��Сɽ�꣬�������涼�Ƕ�ֱ��ʯ�ڣ�
�����������߰�������������Ļҽ�������Ǹ�·������䶼
������¶�ޡ�������һ��ɽ��ͨ�����档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"py5",
]));

	set("outdoors","path1");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
