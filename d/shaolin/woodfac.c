// Room: /wiz/uudd/path2/woodfac.c

inherit ROOM;

void create()
{
	set("short", "��ľ������վ");
	set("long", @LONG
����һ�����ͨ�ķ�ľ����������ľ�������������ľ���һ
�����ִ��Բľ�������м�������������ľ����һ�����˿�����
�㣬���������һ��ͷ��������ͷ������ͷ�Ĺ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k_s14",
]));

	setup();
	replace_program(ROOM);
}
