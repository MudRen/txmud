// Room: /d/changan/badroom.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���ƾɵĵĳ�����������ǰ�������Ϲ�����һ����
�أ������Ͼɣ������������ѱ����޹���ںڵ���ɫ����ʾ��
���������ʢ��
LONG
);
	set(SAFE_ENV, 1);

	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"eroad1",
  "north" : __DIR__"backyard",
]));

	set("objects",([
	__DIR__"npc/keeper" : 1,
	]));

	setup();
	replace_program(ROOM);
}
