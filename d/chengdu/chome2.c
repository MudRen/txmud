// Room: /wiz/louth/c/chome2.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������½���ĺ�Ժ�����������Ƿǳ����������Ը���������
��̳����̳�￪�Ÿ�ɫ���䣬ʯ���̾͵�С·������䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chome1",
]));

	setup();
	replace_program(ROOM);
}
