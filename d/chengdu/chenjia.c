// Room: /wiz/louth/c/chenjia.c

inherit ROOM;

void create()
{
	set("short", "½������");
	set("long", @LONG
�������Ժ�����ţ����ϵ����᲻�ٵط��Ѿ������ˣ�����
��������һ��Сľ�ƣ���д�š�½������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pixiang",
  "enter" : __DIR__"chome1",
]));

	setup();
	replace_program(ROOM);
}
