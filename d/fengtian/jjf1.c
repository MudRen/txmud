// Room: /d/fengtian/jjf1.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
����Ĵ����������ɶ�ߣ��ſ������������ʯʨ�ӣ�����
��צ������һ��������顰����󽫾������������֣��ſڵ�ʯ
�״�ɨ�ĸɸɾ�����������Ƿ���פ����������󽫾��ĸ��ڡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wy6",
  "east" : __DIR__"jjf2",
]));

	set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
