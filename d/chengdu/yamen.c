// Room: /wiz/louth/c/yamen.c

inherit ROOM;

void create()
{
	set("short", "Ѳ������");
	set("long", @LONG
������ǳɶ�����Ѳ�����ţ�����������������ٵ����ڵأ�
�������аڷ���һ�Ŵ����������Ϸ�������һ�顰�����������
���ң����Ե�Ŀ���ϰ���ˮ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"fuenlu",
]));

	setup();
	replace_program(ROOM);
}
