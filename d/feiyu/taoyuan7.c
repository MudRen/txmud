// Room: /wiz/louth/a/taoyuan7.c

inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
���������������һ�����侫�µĻ�԰����÷��������
��أ��������õĶ����߽��ġ�������������ԧ��������䣬��
���Ի��м�ֻ�׺ף�����һ���˼��ɾ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"taoyuan6",
  "north" : __DIR__"taoyuan8",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
