// Room: /d/hangzhou/weaponshop.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�㷢���Լ�վ��һ��������������������ܣ�ǽ�Ϲ�����
��ʽ�����ı����ͷ��ߣ������ǽ�߷���һ�Ź��������湩���
ȴ��һ�ѳ�����ߵ�������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guotaiw3",
]));

	set("objects",([
	__DIR__"npc/weaponboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
