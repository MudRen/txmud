// Room: /d/hangzhou/sudi2.c

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
�����պ��������ľ���֮һ--�յ̡��㲽���������ڵ���
��������Χ�ݳ�ݺ�ɵķ羰���������������˺�����������ÿ��
�����϶�������ϲ�õı��顣
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"stoneroad2",
]));

	setup();
	replace_program(ROOM);
}
