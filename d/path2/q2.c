// Room: /d/path2/q2.c

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
����һ���ưܵ�СԺ�䣬ʯ��ѵ���Ժǽ�кü����Ѿ�����
�ˣ�Ժ����ĵ��ϵ�������ʯ�����ݡ�����ͨ�������ĵ��Ϻ�
�����Ӳݣ������������Ƶģ���������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"q3",
  "south" : __DIR__"q1",
]));

	setup();
	replace_program(ROOM);
}
