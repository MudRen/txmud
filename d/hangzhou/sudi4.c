// Room: /d/hangzhou/sudi4.c

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
  "east" : __DIR__"rockroad3",
]));

	setup();
	replace_program(ROOM);
}
