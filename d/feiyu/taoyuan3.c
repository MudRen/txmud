// Room: /wiz/louth/a/taoyuan3.c

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
  "west" : __DIR__"taoyuan2",
  "east" : __DIR__"taoyuan4",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
