// Room: /d/changan/yaofang.c

inherit ROOM;

void create()
{
	set("short", "������ҩ��");
	set("long", @LONG
�����Ǿ�������ҩ��������ǽ�߰�����һ�˶�ߵ�ҩ��
ӭ����һ�����̨����̨���С�����æµ�š������߹���һ��
��������д�ţ��޺����˼�����������֪��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad2",
  "south" : __DIR__"yaofang2",
]));

	set("objects",([
	__DIR__"npc/huoji" : 1,
]));
	setup();
	replace_program(ROOM);
}
