// Room: /wiz/louth/c/roupu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳɶ��Ϻõ����̡�ÿ�죬���ﶼ���ṩ�ǳ����ʵ���
ţ���⣬���Ҽ۸񹫵������Լ���ȫ�ɶ��������Ƕ����������⡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu3",
]));

	setup();
	replace_program(ROOM);
}
