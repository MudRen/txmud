// Room: /d/hangzhou/fruitshop.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
����һ�侫�µ�С���̣������ϰ����˸�ɫ���ʹ�Ʒ�����
���̵ģ����˲������Ρ�ǽ�ǰ��˼������У������Ѿ����˱�ǩ
�������Ѿ����˶����ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongningn3",
]));


	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
