// Room: /wiz/louth/a/taoyuan10.c

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
  "south" : __DIR__"taoyuan9",
  "northeast" : __DIR__"caodi2",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
