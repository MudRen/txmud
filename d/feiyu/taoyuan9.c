// Room: /wiz/louth/a/taoyuan9.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
���������������һ�����侫�µĻ�԰����÷��������
��أ��������õĶ����߽��ġ�������������ԧ��������䣬��
���Ի��м�ֻ�׺ף�����һ���˼��ɾ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taoyuan8",
  "north" : __DIR__"taoyuan10",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
